#include "Sheep.h"

Sheep::Sheep(int y, int x, World &world) : Animal(y, x, world) {
    strength = 4;
    initiative = 4;
    symbol = 'O';
}
Organism * Sheep::createChild(int y, int x){
    return new Sheep(y, x, world);
}
void Sheep::info(){
    printf("Sheep");
    Organism::info();
}