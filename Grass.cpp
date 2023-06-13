#include "Grass.h"
Grass::Grass(int y, int x, World &world) : Plant(y, x, world) {
    strength = 0;
    symbol = 'T';
}
Organism * Grass::createChild(int y, int x){
    return new Grass(y, x, world);
}

void Grass::info(){
    printf("Grass");
    Organism::info();
}