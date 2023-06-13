#pragma once
#ifndef WORLD_HUMAN_H
#define WORLD_HUMAN_H


#include "Animal.h"
class Animal;

class Human: public Animal {
public:
    Human(int y, int x, World &world);
    void action() override;
    void info() override;
    bool isAbilityActive();
    bool isAbilityAvailable();
    int getAbilityCounter();
    void setAbilityActive(bool value);
    void setAbilityAvailable(bool value);
    void setAbilityCounter(int value);
    bool blockedAttack(Organism * aggressor) override;
    private:
        bool abilityActive;
        bool abilityAvailable;
        int abilityCounter;
};


#endif //WORLD_HUMAN_H
