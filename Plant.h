#ifndef WORLD_PLANT_H
#define WORLD_PLANT_H


#include "Organism.h"
class Organism;
class Plant : public Organism{
public:
    Plant(int y, int x, World &world);
    virtual void action();
protected:
    constexpr static const double PROBABILITY = 0.01;
};


#endif
