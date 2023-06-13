#ifndef WORLD_ANTELOPE_H
#define WORLD_ANTELOPE_H


#include "Animal.h"
class Animal;
class Antelope: public Animal {
public:
    Antelope(int y, int x, World &world);
    void action() override;
    void makeMove(int y, int x) override;
    void collision(Organism * organism) override;
    int getPossibleMovesNumber() override;
    int ** getPossibleMovesCoords() override;
    void info() override;
    Organism * createChild(int y, int x) override;
};


#endif //WORLD_ANTELOPE_H
