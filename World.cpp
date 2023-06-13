#include "World.h"
#include "Antelope.h"
#include "Wolf.h"
#include "Turtle.h"
#include "Fox.h"
#include "Sheep.h"
#include "PineBorscht.h"
#include "Guarana.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Wolfberries.h"
#include "Human.h"

class Human;

class Antelope;
class Fox;
class Sheep;
class Turtle;
class Wolf;

class Dandelion;
class Grass;
class Guarana;
class PineBorscht;
class Wolfberries;

World::World(int sizeY, int sizeX): sizeY(sizeY), sizeX(sizeX){
    turnCounter = 1;
    occupied = new bool * [sizeY];
    for (int y = 0; y < sizeY; ++y) {
        occupied[y] = new bool[sizeX];
        for (int x = 0; x < sizeX; ++x) {
            occupied[y][x] = false;
        }
    }
}

World::World(int sizeY, int sizeX, int animalsNumber, int plantsNumber) :  World(sizeY, sizeX){
    createAnimals(animalsNumber);
    createPlants(plantsNumber);
}


World::World(int sizeY, int sizeX, bool extra, int antelopes, int foxes, int sheep, int turtles, int wolves,
             int dandelions, int grasses, int guaranas, int pineBorschtes, int wolfBerries) : World(sizeY, sizeX){
    turnCounter = 1;
    int y;
    int x;
    for (int i = 0; i < antelopes; ++i) {
        do{
            y = rand() % sizeY;
            x = rand() % sizeX;
        }while(isOccupied(y, x));
        addOrganism(new Antelope(y, x, *this));
    }

    for (int i = 0; i < foxes; ++i) {
        do{
            y = rand() % sizeY;
            x = rand() % sizeX;
        }while(isOccupied(y, x));
        addOrganism(new Fox(y, x, *this));
    }

    for (int i = 0; i < sheep; ++i) {
        do{
            y = rand() % sizeY;
            x = rand() % sizeX;
        }while(isOccupied(y, x));
        addOrganism(new Sheep(y, x, *this));
    }

    for (int i = 0; i < turtles; ++i) {
        do{
            y = rand() % sizeY;
            x = rand() % sizeX;
        }while(isOccupied(y, x));
        addOrganism(new Turtle(y, x, *this));
    }

    for (int i = 0; i < wolves; ++i) {
        do{
            y = rand() % sizeY;
            x = rand() % sizeX;
        }while(isOccupied(y, x));
        addOrganism(new Wolf(y, x, *this));
    }

    for (int i = 0; i < dandelions; ++i) {
        do{
            y = rand() % sizeY;
            x = rand() % sizeX;
        }while(isOccupied(y, x));
        addOrganism(new Dandelion(y, x, *this));
    }

    for (int i = 0; i < grasses; ++i) {
        do{
            y = rand() % sizeY;
            x = rand() % sizeX;
        }while(isOccupied(y, x));
        addOrganism(new Grass(y, x, *this));
    }

    for (int i = 0; i < guaranas; ++i) {
        do{
            y = rand() % sizeY;
            x = rand() % sizeX;
        }while(isOccupied(y, x));
        addOrganism(new Guarana(y, x, *this));
    }

    for (int i = 0; i < pineBorschtes; ++i) {
        do{
            y = rand() % sizeY;
            x = rand() % sizeX;
        }while(isOccupied(y, x));
        addOrganism(new PineBorscht(y, x, *this));
    }

    for (int i = 0; i < wolfBerries; ++i) {
        do{
            y = rand() % sizeY;
            x = rand() % sizeX;
        }while(isOccupied(y, x));
        addOrganism(new Wolfberries(y, x, *this));
    }
}


World::World(char * fileName){
    FILE    *file;
    char line[BUFFER];
    sprintf(line, "./../%s.txt", fileName);
    file = fopen(line, "r");
    if(file == nullptr){
        printf("Loading the world failed.\nCheck if the name of the file is proper.");
    }
    else{
        turnCounter = 0;
        int abilityActive;
        int abilityAvailable;
        int abilityCounter;
        int organismsNumber;
        char symbol;
        int strength;
        int initiative;
        Organism * organism;
        fgets(line, BUFFER, file);
        sscanf (line,"%d,%d",&sizeY,&sizeX);
        occupied = new bool * [sizeY];
        for (int y = 0; y < sizeY; ++y) {
            occupied[y] = new bool[sizeX];
            for (int x = 0; x < sizeX; ++x) {
                occupied[y][x] = false;
            }
        }
        fgets(line, BUFFER, file);
        sscanf (line,"%d,%d,%d",&abilityActive,&abilityAvailable, &abilityCounter);
        fgets(line, BUFFER, file);
        sscanf(line, "%d", &organismsNumber);
        for (int i = 0; i < organismsNumber; ++i) {
            int y;
            int x;
            fgets(line, BUFFER, file);
            sscanf (line,"%c,%d,%d,%d,%d",&symbol, &y, &x,&strength, &initiative);
            switch (symbol) {
                case 'A':
                    organism = new Antelope(y, x, *this);
                    break;
                case 'C':
                    organism = new Human(y, x, *this);
                    dynamic_cast<Human*>(organism)->setAbilityActive(abilityActive);
                    dynamic_cast<Human*>(organism)->setAbilityAvailable(abilityAvailable);
                    dynamic_cast<Human*>(organism)->setAbilityCounter(abilityCounter);
                    break;
                case 'L':
                    organism = new Fox(y, x, *this);
                    break;
                case 'O':
                    organism = new Sheep(y, x, *this);
                    break;
                case 'W':
                    organism = new Wolf(y, x, *this);
                    break;
                case 'Z':
                    organism = new Turtle(y, x, *this);
                    break;
                case 'B':
                    organism = new Wolfberries(y, x, *this);
                    break;
                case 'G':
                    organism = new Guarana(y, x, *this);
                    break;
                case 'M':
                    organism = new Dandelion(y, x, *this);
                    break;
                case 'T':
                    organism = new Grass(y, x, *this);
                    break;
                case 'J':
                    organism = new Wolfberries(y, x, *this);
                    break;
            }
            organism->setStrength(strength);
            organism->setInitiative(initiative);
            addOrganism(organism);
        }
        fclose(file);
    }
}


void World::createAnimals(int n){
    for (int i = 0; i < n; ++i) {
        int choice = rand() % ANIMAL_SPECIES_NUMBER;
        int y;
        int x;
        do{
            y = rand() % sizeY;
            x = rand() % sizeX;
        }while(isOccupied(y, x));
        switch (choice) {
            case 0:
                addOrganism(new Antelope(y, x, *this));
                break;
            case 1:
                addOrganism(new Fox(y, x, *this));
                break;
            case 2:
                addOrganism(new Sheep(y, x, *this));
                break;
            case 3:
                addOrganism(new Turtle(y, x, *this));
                break;
            case 4:
                addOrganism(new Wolf(y, x, *this));
                break;
            default:
                printf("No such an animal...\n");
        }
    }
}

void World::createPlants(int n){
    for (int i = 0; i < n; ++i) {
        int choice = rand() % ANIMAL_SPECIES_NUMBER;
        int y;
        int x;
        do{
            y = rand() % sizeY;
            x = rand() % sizeX;
        }while(isOccupied(y, x));
        switch (choice) {
            case 0:
                addOrganism(new Dandelion(y, x, *this));
                break;
            case 1:
                addOrganism(new Grass(y, x, *this));
                break;
            case 2:
                addOrganism(new Guarana(y, x, *this));
                break;
            case 3:
                addOrganism(new PineBorscht(y, x, *this));
                break;
            case 4:
                addOrganism(new Wolfberries(y, x, *this));
                break;
            default:
                printf("No such an animal...\n");
        }
    }
}

void World::makeTurn(){
    sortOrganisms();
    turnCounter += 1;
    int counter = 0;
    for (int y = 0; y < sizeY; ++y) {
        for (int x = 0; x < sizeX; ++x) {
            if(isOccupied(y, x)){
                counter+=1;
            }
        }
    }
    for (int i = 0; i < organisms.size(); ++i) {
        organisms.get(i)->action();
        updateState();
    }

}
void World::print(){
    printf("\n\nName: Michal,\tSurname: Ganczarenko\tIndex nr: 188818\n");
    printf("Turn nr: %d\n", turnCounter);
    printf("+");
    for (int x = 0; x < sizeX; ++x) {
        printf("--");
    }
    printf("-+\n");
    for (int y = 0; y < sizeY; ++y) {
        printf("|");
        for (int x = 0; x < sizeX; ++x) {
            printf(" ");
            if(occupied[y][x]){
                findOrganismOnTile(y, x)->print();
            }
            else{
                printf(" ");
            }
        }
        printf(" |\n");
    }
    printf("+");
    for (int x = 0; x < sizeX; ++x) {
        printf("--");
    }
    printf("-+\n");
}

bool World::coordsValid(int y, int x) const{
    return y >= 0 && x >= 0 && y < sizeY && x < sizeX;
}
bool World::isOccupied(int y, int x){
    return occupied[y][x];
}

void World::updateState(){
    for (int y = 0; y < sizeY; ++y) {
        for (int x = 0; x < sizeX; ++x) {
            occupied[y][x] = (findOrganismOnTile(y, x) != nullptr);
        }
    }
}
Organism* World::findOrganismOnTile(int y, int x){
    for (int i = 0; i < organisms.size(); ++i) {
        int orgY = organisms.get(i)->getY();
        int orgX = organisms.get(i)->getX();
        if(y == orgY && x == orgX)
            return organisms.get(i);
    }
    return nullptr;
}

void World::addOrganism(Organism * organism){
    if(organisms.size() < ORGANISMS_NUMBER_LIMIT){
        organisms.append(organism);
        updateState();
    }
    else{
        printf("To many organisms to add one more\n");
    }
}

void World::deleteOrganism(Organism * organism){
    int index = organisms.index(organism);
    organisms.pop(index);
    delete organism;
}
void World::sortOrganisms(){
    int currentMaxIndex;
    Organism * temp;
    for (int i = 0; i < organisms.size(); ++i) {
        currentMaxIndex = i;
        for (int j = i+1; j < organisms.size(); ++j) {
            if(organisms.get(j)->getInitiative() > organisms.get(currentMaxIndex)->getInitiative()){
                currentMaxIndex = j;
            }
        }
        temp = organisms.get(currentMaxIndex);
        organisms.replace(currentMaxIndex, organisms.get(i));
        organisms.replace(i, temp);
    }
}

void World::safeWorldData(char * fileName){
    char * txt = new char[BUFFER];
    sprintf(txt, "./../%s.txt", fileName);
    FILE *file;
    file = fopen(txt, "w");

    if(file == nullptr) {
        printf("file couldn't be opened\n");
        exit(1);
    }
    sprintf(txt, "%d,%d\n", sizeY, sizeX);
    fputs(txt,file);
    if(findHumanIndex() != -1){
        Human * human = dynamic_cast<Human*>(organisms.get(findHumanIndex()));
        sprintf(txt, "%d,%d,%d\n", human->isAbilityActive(),
                human->isAbilityAvailable(), human->getAbilityCounter());
    }
    else{
        sprintf(txt, "-1,-1,-1\n");
    }
    fputs(txt,file);
    sprintf(txt, "%d\n", organisms.size());
    fputs(txt,file);
    for (int i = organisms.size()-1; i >= 0; --i) {
        Organism * organism = organisms.get(i);
        sprintf(txt, "%c,%d,%d,%d,%d\n", organism->getSymbol(), organism->getY(),
                organism->getX(), organism->getStrength(), organism->getInitiative());
        fputs(txt,file);
    }
    fclose(file);
}



int World::findHumanIndex(){
    for (int i = 0; i < organisms.size(); ++i) {
        if(dynamic_cast<Human*>(organisms.get(i)) != nullptr){
            return i;
        }
    }
    return -1;
}
bool World::adjoiningTiles(int y1, int x1, int y2, int x2){
    return abs(x1 - x2) + abs(y1 - y2) < 2 || (abs(x1 - x2) == 1 && abs(y1 - y2));
}