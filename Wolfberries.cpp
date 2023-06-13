#include "Wolfberries.h"

Wolfberries::Wolfberries(int y, int x, World &world) : Plant(y, x, world) {
    strength = 99;
    symbol = 'J';
}

Organism * Wolfberries::createChild(int y, int x){
    return new Wolfberries(y, x, world);
}

void Wolfberries::info(){
    printf("Wolfberries");
    Organism::info();
}