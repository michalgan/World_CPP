#include "Organism.h"

Organism::Organism(int y, int x, World &world)
: position(y, x), world(world), lastPosition(y, x){}


int Organism::getY() const{
    return position.y;
}
int Organism::getX() const{
    return position.x;
}

int Organism::getStrength() const{
    return strength;
}
int Organism::getInitiative() const{
    return initiative;
}
char Organism::getSymbol() const{
    return symbol;
}


void Organism::setStrength(int value){
    this->strength = value;
}
void Organism::setInitiative(int value){
    this->initiative = value;
}

void Organism::info() {
    printf("(S %d, I %d, Y %d, X %d)", strength, initiative ,position.y, position.x);
}

void Organism::action(){}
void Organism::collision(Organism* organism){}
void Organism::print(){
    printf("%c", symbol);
}
void Organism::kill(Organism * killer){
    world.deleteOrganism(this);
}
Organism * Organism::createChild(int y, int x) {
    return new Organism(y, x, world);
}

int Organism::getAdjoiningClearTileNumber(){
    int objY = position.y;
    int objX = position.x;
    int counter = 0;
    for (int y = objY-1; y <= objY+1; ++y) {
        for (int x = objX-1; x <= objX+1; ++x) {
            if(world.coordsValid(y, x) && !(world.isOccupied(y, x))){
                counter += 1;
            }
        }
    }
    return counter;
}
int** Organism::getAdjoiningClearTileCoords(){
    int n = getAdjoiningClearTileNumber();
    int ** coords = new int * [n];
    int objY = position.y;
    int objX = position.x;
    int counter = 0;
    for (int y = objY-1; y <= objY+1; ++y) {
        for (int x = objX-1; x <= objX+1; ++x) {
            if(world.coordsValid(y, x) && !(world.isOccupied(y, x))){
                coords[counter] = new int[2];
                coords[counter][0] = y;
                coords[counter][1] = x;
                counter += 1;
            }
        }
    }
    return coords;
}


bool Organism::blockedAttack(Organism * aggressor){
    return false;
}