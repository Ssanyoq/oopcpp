#ifndef OOPCPP_PLACEABLE_H
#define OOPCPP_PLACEABLE_H

#include "sprite.h"

enum ObjectType { // TODO
    Base,
    Turret,
    Spawn,
    Other,
    Danger
};
class Entity;

class Placeable : public Sprite {
public:
    Placeable(long long int x=-1, long long int y=-1, short rotation=0) : Sprite(x, y,
                                                                         rotation) {};

    virtual void doAction(std::vector<Entity> &entities) {};

    virtual ObjectType getType() const {return Other;}; // TODO
};

#endif
