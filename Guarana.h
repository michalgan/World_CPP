#ifndef WORLD_GUARANA_H
#define WORLD_GUARANA_H


#include "Plant.h"
class Plant;
class Guarana: public Plant {
public:
    Guarana(int y, int x, World &world);
    Organism * createChild(int y, int x) override;
    void info() override;
    void kill(Organism * killer) override;
};


#endif
