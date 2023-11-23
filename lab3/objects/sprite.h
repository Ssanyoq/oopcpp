#ifndef OOPCPP_SPRITE_H
#define OOPCPP_SPRITE_H

#include <utility>
#include "../utility/coords.h"

#define ll long long

using std::pair;

class Sprite {
protected:
    Coordinates position;
    short rotationDegree;
public:
    explicit Sprite(ll x, ll y, short rotation = 0) : position({.x = x, .y = y}), rotationDegree(rotation) {};

    explicit Sprite(Coordinates coords, short rotation = 0) : position(coords), rotationDegree(rotation) {};

    Coordinates getPos() const { return position; };

    void dummyDraw() const {};

    void setRotation(short newDirection) { rotationDegree = newDirection; };
};

#endif
