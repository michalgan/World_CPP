#include "Animal.h"


Animal::Animal(int y, int x, World &world): Organism(y, x, world) {}
void Animal::action(){
    int n = getPossibleMovesNumber();
    if(n > 0){
        int move = rand() % n;
        int ** coords = getPossibleMovesCoords();
        int y = coords[move][0];
        int x = coords[move][1];
        delete coords;
        makeMove(y, x);
        delete coords;
    }
    else{
        info();
        printf(" didn't make move\n");
    }

}

void Animal::makeMove(int y, int x){
    info();
    printf(" made move on position (%d, %d)\n", y, x);
    if(world.isOccupied(y, x)){
        collision(world.findOrganismOnTile(y, x));
    }
    else{
        position = Coordinates(y, x);
        lastPosition = position;
        world.updateState();
    }
}


void Animal::collision(Organism * organism){
    position = Coordinates(organism->getY(), organism->getX());
    world.updateState();
    info();
    printf(" had collision with ");
    organism->info();
    printf("\n");
    if(symbol == organism->getSymbol()){
        multiplication(organism);
    }
    else{
        if(strength < organism->getStrength()){
            info();
            printf(" has been killed by ");
            organism->info();
            printf("\n");
            kill(organism);
        }
        else{
            position = Coordinates(organism->getY(), organism->getX());
            world.updateState();
            if(organism->blockedAttack(this)){
                int n = getAdjoiningClearTileNumber();
                int ** coords = getAdjoiningClearTileCoords();
                int move = rand() % n;
                int y = coords[move][0];
                int x = coords[move][1];
                delete coords;
                makeMove(y, x);
            }
            else{
                organism->info();
                printf(" has been killed by ");
                info();
                printf("\n");
                organism->kill(this);
            }
        }
    }
}

void Animal::multiplication(Organism * organism){
    int y1 = position.y;
    int x1 = position.x;
    int y2 = organism->getY();
    int x2 = organism->getX();
    int ** possibleTiles = new int * [ADJOINING_TILES];
    int counter = 0;
    for (int y = y1-1; y <= y1+1; ++y) {
        for (int x = x1-1; x <= x1+1; ++x) {
            if(world.coordsValid(y, x) && !(world.isOccupied(y, x)) && world.adjoiningTiles(y2, x2, y, x)){
                possibleTiles[counter] = new int[2];
                possibleTiles[counter][0] = y;
                possibleTiles[counter++][1] = x;
            }
        }
    }
    if(counter > 0){
        int choice = rand() % counter;
        Organism * child = createChild(possibleTiles[choice][0], possibleTiles[choice][1]);
        delete[] possibleTiles;
        world.addOrganism(child);
        printf("A new organism has shown: ");
        child->info();
        printf("\n");
    }
}
int Animal::getPossibleMovesNumber(){
    int objY = position.y;
    int objX = position.x;
    int counter = 0;
    for (int y = objY-1; y <= objY+1; ++y) {
        for (int x = objX-1; x <= objX+1; ++x) {
            if(world.coordsValid(y, x) && !(x == objX && y == objY) && position.distance(y, x) < 2){
                counter += 1;
            }
        }
    }
    return counter;
}
int ** Animal::getPossibleMovesCoords(){
    int objY = position.y;
    int objX = position.x;
    int n = getPossibleMovesNumber();
    int ** coords = new int * [n];
    int counter = 0;
    for (int y = objY-1; y <= objY+1; ++y) {
        for (int x = objX-1; x <= objX+1; ++x) {
            if(world.coordsValid(y, x) && !(x == objX && y == objY) && position.distance(y, x) < 2){
                coords[counter] = new int[2];
                coords[counter][0] = y;
                coords[counter++][1] = x;
            }
        }
    }
    return coords;
}
