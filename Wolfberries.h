#ifndef WORLD_WOLFBERRIES_H
#define WORLD_WOLFBERRIES_H


#include "Plant.h"
class Plant;
class Wolfberries: public Plant {
public:
    Wolfberries(int y, int x, World &world);
    Organism * createChild(int y, int x) override;
    void info() override;
};


#endif
