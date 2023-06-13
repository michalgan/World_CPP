#include "Dandelion.h"
Dandelion::Dandelion(int y, int x, World &world) : Plant(y, x, world) {
    strength = 0;
    symbol = 'M';
}
void Dandelion::action() {
    for (int i = 0; i < 3; ++i) {
        Plant::action();
    }
}
Organism * Dandelion::createChild(int y, int x) {
    return new Dandelion(y, x, world);
}
void Dandelion::info(){
    printf("Dandelion");
    Organism::info();
}