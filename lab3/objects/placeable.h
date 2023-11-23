#ifndef OOPCPP_PLACEABLE_H
#define OOPCPP_PLACEABLE_H

#include "sprite.h"

class Placeable : public Sprite {
public:
    Placeable(const Game &currentGame, long long int x, long long int y, short rotation) : Sprite(currentGame, x, y,
                                                                                                  rotation) {};

    virtual void doAction() = 0;
}

#endif
