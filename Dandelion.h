#ifndef WORLD_DANDELION_H
#define WORLD_DANDELION_H


#include "Plant.h"
class Plant;
class Dandelion: public Plant {
public:
    Dandelion(int y, int x, World &world);
    void action() override;
    Organism * createChild(int y, int x) override;
    void info() override;
};


#endif
