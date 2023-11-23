#ifndef OOPCPP_SPRITE_H
#define OOPCPP_SPRITE_H

#include <utility>
#include "../game_features/game.h"
#include "../utitlity/coords.h"

#define ll long long

using std::pair;

class Sprite {
protected:
    Coordinates position;
    short rotationDegree;
    const Game &game;
public:
    Sprite(const Game &currentGame, ll x, ll y, short rotation = 0) : game(currentGame),
                                                                      position({.x = x, .y = y}),
                                                                      rotationDegree(rotation) {};

    Sprite(const Game &currentGame, Coordinates coords, short rotation = 0) : game(currentGame),
                                                                              position(coords),
                                                                              rotationDegree(rotation) {};

    Coordinates getPos() const { return position; };

    void dummyDraw() {};

    void move();

    void rotate(short newDirection) { rotationDegree = newDirection; };
};

#endif
