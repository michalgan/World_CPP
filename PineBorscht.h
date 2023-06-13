#ifndef WORLD_PINEBORSCHT_H
#define WORLD_PINEBORSCHT_H


#include "Plant.h"
class Plant;
class PineBorscht: public Plant {
public:
    PineBorscht(int y, int x, World &world);
    void action()override;
    Organism * createChild(int y, int x) override;
    void info() override;
};


#endif //WORLD_PINEBORSCHT_H
