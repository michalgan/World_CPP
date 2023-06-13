#pragma once
#ifndef WORLD_ANIMAL_H
#define WORLD_ANIMAL_H
#include "Organism.h"
class Organism;

class Animal: public Organism {
protected:
    Animal(int y, int x, World &world);
    virtual void action() override;
    virtual void makeMove(int y, int x);
    virtual void collision(Organism * organism) override;
    virtual void multiplication(Organism * organism);
    virtual int getPossibleMovesNumber();
    virtual int ** getPossibleMovesCoords();
};


#endif //WORLD_ANIMAL_H
