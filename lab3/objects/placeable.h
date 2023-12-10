#ifndef OOPCPP_PLACEABLE_H
#define OOPCPP_PLACEABLE_H

#include "sprite.h"

class Placeable : public Sprite {
public:
    Placeable(long long int x=-1, long long int y=-1, short rotation=0) : Sprite(x, y,
                                                                         rotation) {};

    virtual void doAction() {};
};

#endif
