#pragma once
#ifndef WORLD_WORLD_H
#define WORLD_WORLD_H

#include "List.h"
#include "Organism.h"

class Organism;
class World {
public:
    World(int sizeY, int sizeX);
    World(int sizeY, int sizeX, int animalsNumber, int plantsNumber);
    World(int sizeY, int sizeX, bool extra, int antelopes = 0, int foxes = 0, int sheep = 0, int turtles = 0, int wolves = 0,
          int dandelions = 0, int grasses = 0, int guaranas = 0, int pineBorschtes = 0, int wolfBerries = 0);
    World(char * fileName);
    void createAnimals(int n);
    void createPlants(int n);
    void makeTurn();
    void print();
    bool coordsValid(int y, int x) const;
    bool isOccupied(int y, int x);
    void updateState();
    Organism* findOrganismOnTile(int y, int x);
    void addOrganism(Organism * organism);
    void deleteOrganism(Organism * organism);
    void sortOrganisms();
    void safeWorldData(char * fileName);
    int findHumanIndex();
    static bool adjoiningTiles(int y1, int x1, int y2, int x2);
private:
    bool ** occupied;
    int sizeY, sizeX;
    List<Organism*> organisms;
    int turnCounter;
    static const int ANIMAL_SPECIES_NUMBER = 5;
    static const int PLANT_SPECIES_NUMBER = 5;
    static const int ORGANISMS_NUMBER_LIMIT = 200;
    static const int BUFFER = 100;
};


#endif //WORLD_WORLD_H
