#ifndef WORLD_SHEEP_H
#define WORLD_SHEEP_H


#include "Animal.h"
class Animal;

class Sheep: public Animal {
public:
    Sheep(int y, int x, World &world);
    Organism * createChild(int y, int x) override;
    void info() override;
};


#endif
