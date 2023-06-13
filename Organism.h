#pragma once
#ifndef WORLD_ORGANISM_H
#define WORLD_ORGANISM_H


#include "Coordinates.h"
#include "World.h"
class World;

class Organism {
public:
    Organism(int y, int x, World& world);
    int getY() const;
    int getX() const;
    int getStrength() const;
    int getInitiative() const;
    char getSymbol() const;
    void setStrength(int value);
    void setInitiative(int value);
    virtual void kill(Organism * killer);
    virtual void action();
    virtual void collision(Organism* organism);
    virtual void print();
    virtual void info();
    virtual Organism * createChild(int y, int x);
    int getAdjoiningClearTileNumber();
    int** getAdjoiningClearTileCoords();
    virtual bool blockedAttack(Organism * aggressor);

protected:
    int strength;
    int initiative;
    char symbol;
    Coordinates position;
    Coordinates lastPosition;
    World& world;
    static const int ADJOINING_TILES = 8;
};


#endif
