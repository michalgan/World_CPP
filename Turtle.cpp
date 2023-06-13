#include "Turtle.h"
Turtle::Turtle(int y, int x, World &world) : Animal(y, x, world) {
    strength = 2;
    initiative = 1;
    symbol = 'Z';}

void Turtle::action() {
    if(rand() % 4 == 0){
        Animal::action();
    }
}

void Turtle::collision(Organism * organism){
    if(organism->getStrength() >= 5){
        Animal::collision(organism);
    }
}


Organism * Turtle::createChild(int y, int x){
    return new Turtle(y, x, world);
}

void Turtle::info(){
    printf("Turtle");
    Organism::info();
}

bool Turtle::blockedAttack(Organism * aggressor){
    if(aggressor->getStrength() < 5){
        info();
        printf(" blocked an attack of ");
        aggressor->info();
        printf("\n");
    }
    return aggressor->getStrength() < 5;
}