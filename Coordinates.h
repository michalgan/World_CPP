#pragma once
#ifndef WORLD_COORDINATES_H
#define WORLD_COORDINATES_H


#include <cmath>

struct Coordinates {
    Coordinates(int y, int x): y(y), x(x){};
    int y;
    int x;
    int distance(int argY, int arbX) const{
        return abs(this->y - argY) + abs(this->x - arbX);
    }
};


#endif //WORLD_COORDINATES_H
