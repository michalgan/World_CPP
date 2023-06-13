#ifndef WORLD_FOX_H
#define WORLD_FOX_H


#include "Animal.h"
class Animal;
class Fox: public Animal{
public:
    Fox(int y, int x, World &world);
    void action() override;
    Organism * createChild(int y, int x) override;
    void info() override;
};


#endif
