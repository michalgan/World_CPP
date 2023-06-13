#ifndef WORLD_TURTLE_H
#define WORLD_TURTLE_H


#include "Animal.h"
class Animal;
class Turtle: public Animal{
public:
    Turtle(int y, int x, World &world);
    void action() override;
    void collision(Organism * organism) override;
    Organism * createChild(int y, int x) override;
    void info() override;
    bool blockedAttack(Organism * aggressor) override;
};


#endif
