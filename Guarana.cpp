#include "Guarana.h"

Guarana::Guarana(int y, int x, World &world) : Plant(y, x, world) {
    strength = 0;
    symbol = 'G';
}

Organism * Guarana::createChild(int y, int x) {
    return new Guarana(y, x, world);
}
void Guarana::info(){
    printf("Guarana");
    Organism::info();
}
void Guarana::kill(Organism * killer) {
    killer->setStrength(killer->getStrength()+3);
    info();
    printf(" increased strength of ");
    killer->info();
    printf(" by 3\n");
    Organism::kill(killer);
}