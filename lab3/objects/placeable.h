#ifndef OOPCPP_PLACEABLE_H
#define OOPCPP_PLACEABLE_H

#include "sprite.h"

class Placeable : public Sprite {
public:
    Placeable(long long int x, long long int y, short rotation) : Sprite(x, y,
                                                                         rotation) {};

    virtual void doAction() {};
};

#endif
