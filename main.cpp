#include "Human.h"

int main() {
    srand(time(NULL));
    World world = World(10, 30, false,  10,10, 10, 10, 5,
                        10, 10, 10, 5, 10);
    // World world = World("save");
    int y = 0;
    int x = 0;
    while(world.isOccupied(y, x)){
        y = rand() % 10;
        x = rand() % 30;
    }
    Human  * human = new Human(y, x, world);
    world.addOrganism(human);
    for (int i = 0; i < 100; ++i) {
        world.print();
        world.makeTurn();
        // system ("CLS");
    }
    world.print();
    // world.safeWorldData("save");
    return 0;
}
