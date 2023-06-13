#include "PineBorscht.h"

PineBorscht::PineBorscht(int y, int x, World &world)
: Plant(y, x, world) {
    strength = 10;
    symbol = 'B';
}
void PineBorscht::action(){
    int objY = position.y;
    int objX = position.x;
    for (int y = objY-1; y <= objY+1; ++y) {
        for (int x = objX-1; x <= objX+1; ++x) {
            if(world.coordsValid(y, x) && !(y == objY && x == objX) && world.isOccupied(y, x)){
                Organism * organism = world.findOrganismOnTile(y, x);
                organism->info();
                printf(" got poisoned by near ");
                info();
                printf("\n");
                organism->kill(organism);
            }
        }
    }
}
Organism * PineBorscht::createChild(int y, int x){
    return new PineBorscht(y, x, world);
}

void PineBorscht::info(){
    printf("PineBorscht");
    Organism::info();
}