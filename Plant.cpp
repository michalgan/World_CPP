#include "Plant.h"
Plant::Plant(int y, int x, World &world) : Organism(y, x, world) {
    initiative = 0;
}

void Plant::action() {
    int n = getAdjoiningClearTileNumber();
    int ** coords = getAdjoiningClearTileCoords();
    if(n > 0 && rand() % 100 < 100*PROBABILITY){
        int move = rand() % n;
        int y = coords[move][0];
        int x = coords[move][1];
        Organism * child = createChild(y, x);
        printf("A new organism has shown: ");
        child->info();
        printf("\n");
        world.addOrganism(child);
    }

}

