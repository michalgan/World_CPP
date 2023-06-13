#include <conio.h>
#include "Human.h"

Human::Human(int y, int x, World &world) : Animal(y, x, world){
    abilityActive = false;
    abilityAvailable = true;
    abilityCounter = 0;
    strength = 5;
    initiative = 4;
    symbol = 'C';
}
void Human::info(){
    printf("Human");
    Organism::info();
}

void  Human::action(){
    world.print();
    if(abilityActive || !abilityAvailable){
        abilityCounter += 1;
        if(abilityCounter == 5){
            abilityCounter = 0;
            if(abilityActive){
                abilityActive = false;
                printf("Human skill is now inactive\n");
            }
            else{
                abilityAvailable = true;
                printf("Human skill is now available\n");
            }
        }
    }
    int y = this->position.y;
    int x = this->position.x;
    int newY = y;
    int newX = x;
    bool madeMove = false;
    char zn;
    do{
        zn = getch();
        if(zn == 0) {
            zn = getch();
            if(zn == 0x48){
                newY--;
            }
            else if(zn == 0x50){
                newY++;
            }
            else if(zn == 0x4b){
                newX--;
            }
            else if(zn == 0x4d){
                newX++;
            }
            if(world.coordsValid(newY, newX) && !(y == newY && x == newX)){
                lastPosition = position;
                info();
                printf(" changed position to (%d, %d)\n", newY, newX);
                madeMove = true;
                if(world.isOccupied(newY, newX)){
                    collision(world.findOrganismOnTile(newY, newX));
                }
                position = Coordinates(newY, newX);
            }
        }
        else if(zn == ' ' && !abilityActive && abilityAvailable){
            printf("Human activated skill\n");
            abilityActive = true;
            abilityAvailable = false;
        }
    }while(!madeMove);

}


bool Human::isAbilityActive(){
    return abilityActive;
}


bool Human::isAbilityAvailable(){
    return abilityAvailable;
}


int Human::getAbilityCounter(){
    return abilityCounter;
}


void Human::setAbilityActive(bool value){
    abilityActive = value;
}


void Human::setAbilityAvailable(bool value){
     abilityAvailable = value;
}


void Human::setAbilityCounter(int value){
    abilityCounter = value;
}


bool Human::blockedAttack(Organism * aggressor){
    if(abilityActive){
        info();
        printf(" blocked attack of ");
        aggressor->info();
        printf(" thanks to Alzur's Shield\n");
    }
    return abilityActive;
}