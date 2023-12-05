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
    bool invisible = false;
public:
    explicit Sprite(ll x, ll y, short rotation = 0, bool invisible = false) : position({.x = x, .y = y}), rotationDegree(rotation) {};

    explicit Sprite(Coordinates coords, short rotation = 0) : position(coords), rotationDegree(rotation) {};

    Coordinates getPos() const { return position; };

    void dummyDraw() const {};

    void changeVisibility(bool isInvisible);

    void setRotation(short newDirection) { rotationDegree = newDirection; };
};

#endif
