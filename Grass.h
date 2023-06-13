#ifndef WORLD_GRASS_H
#define WORLD_GRASS_H


#include "Plant.h"
class Plant;
class Grass: public Plant {
public:
    Grass(int y, int x, World &world);
    Organism * createChild(int y, int x) override;
    void info() override;
};


#endif
