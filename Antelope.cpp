#include "Antelope.h"
Antelope::Antelope(int y, int x, World &world) : Animal(y, x, world) {
    strength = 4;
    initiative = 4;
    symbol = 'A';
}

void Antelope::action(){
    int n = getPossibleMovesNumber();
    if(n > 0){
        int move = rand() % n;
        int ** coords = getPossibleMovesCoords();
        int y = coords[move][0];
        int x = coords[move][1];
        delete coords;
        makeMove(y, x);
    }
    else{
        info();
        printf(" didn't make move\n");
    }

}

void Antelope::makeMove(int y, int x){
    info();
    printf(" made move on position (%d, %d)\n", y, x);
    if(world.isOccupied(y, x)){
        collision(world.findOrganismOnTile(y, x));
    }
    else{
        position = Coordinates(y, x);
        world.updateState();
        lastPosition = position;
    }
}

void Antelope::collision(Organism * organism){
    if(strength <= organism->getStrength() && (getAdjoiningClearTileNumber() != 0 || rand() % 2 == 1)){
        int n = getAdjoiningClearTileNumber();
        int ** coords = getAdjoiningClearTileCoords();
        srand(time(NULL));
        int move = rand() % n;
        int y = coords[move][0];
        int x = coords[move][1];
        for (int i = 0; i < n; ++i) {
            delete coords[i];
        }
        delete coords;
        lastPosition = position;
        position = Coordinates(y, x);
        world.updateState();
        info();
        printf(" escaped from ");
        organism->info();
        printf("\n");
    }
    else{
        Animal::collision(organism);
    }
}
int Antelope::getPossibleMovesNumber(){
    int objY = position.y;
    int objX = position.x;
    int counter = 0;
    for (int y = objY-1; y <= objY+1; ++y) {
        for (int x = objX-1; x <= objX+1; ++x) {
            if(world.coordsValid(y, x) && !(y == objY && x == objX)){
                counter += 1;
            }
        }
    }
    if(world.coordsValid(objY + 2, objX)) counter += 1;
    if(world.coordsValid(objY, objX + 2)) counter += 1;
    if(world.coordsValid(objY - 2, objX)) counter += 1;
    if(world.coordsValid(objY, objX - 2)) counter += 1;
    return counter;
}
int ** Antelope::getPossibleMovesCoords(){
    int objY = position.y;
    int objX = position.x;
    int counter = 0;
    int n = getPossibleMovesNumber();
    int ** coords = new int * [n];
    for (int y = objY-1; y <= objY+1; ++y) {
        for (int x = objX-1; x <= objX+1; ++x) {
            if(world.coordsValid(y, x) && !(y == objY && x == objX)){
                coords[counter] = new int[2];
                coords[counter][0] = y;
                coords[counter++][1] = x;
            }
        }
    }
    int extraCoords[4][2] = {{objY + 2, objX}, {objY, objX + 2}, {objY - 2, objX}, {objY, objX - 2}};
    for (auto & extraCoord : extraCoords) {
        int y = extraCoord[0];
        int x = extraCoord[1];
        if(world.coordsValid(y, x)){
            coords[counter] = new int[2];
            coords[counter][0] = y;
            coords[counter++][1] = x;
        }
    }
    return coords;
}
void Antelope::info(){
    printf("Antelope");
    Organism::info();
}
Organism * Antelope::createChild(int y, int x){
    return new Antelope(y, x, world);
}