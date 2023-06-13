#ifndef WORLD_WOLF_H
#define WORLD_WOLF_H


#include "Animal.h"
class Animal;

class Wolf : public Animal{
public:
    Wolf(int y, int x, World &world);
    Organism * createChild(int y, int x) override;
    void info() override;
};


#endif
