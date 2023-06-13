#include "Wolf.h"
Wolf::Wolf(int y, int x, World &world) : Animal(y, x, world) {
    strength = 9;
    initiative = 5;
    symbol = 'W';
}
Organism * Wolf::createChild(int y, int x){
    return new Wolf(y, x, world);
}
void Wolf::info(){
    printf("Wolf");
    Organism::info();
}