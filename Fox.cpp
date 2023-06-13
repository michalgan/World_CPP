#include "Fox.h"

Fox::Fox(int y, int x, World &world) : Animal(y, x, world) {
    strength = 3;
    initiative = 7;
    symbol = 'L';
}

Organism * Fox::createChild(int y, int x){
    return new Fox(y, x, world);
}
void Fox::action(){
    int n = getPossibleMovesNumber();
    if(n > 0){
        int counter = 0;
        int ** coords = getPossibleMovesCoords();
        int ** newCoords = new int * [n];
        for (int i = 0; i < n; ++i) {
            int y = coords[i][0];
            int x = coords[i][1];
            if(!(world.isOccupied(y, x) && world.findOrganismOnTile(y, x)->getStrength() > strength)){
                newCoords[counter] = new int[2];
                newCoords[counter][0] = y;
                newCoords[counter++][1] = x;
            }
        }
        if(counter > 0){
            int move = rand() % counter;
            int y = newCoords[move][0];
            int x = newCoords[move][1];
            makeMove(y, x);
        }
        else{
            info();
            printf(" didn't make move\n");
        }
    }
    else{
        info();
        printf(" didn't make move\n");
    }
}
void Fox::info(){
    printf("Fox");
    Organism::info();
}