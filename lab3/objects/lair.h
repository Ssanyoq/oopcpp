#ifndef OOPCPP_LAIR_H
#define OOPCPP_LAIR_H

#include "placeable.h"
#include <vector>

using std::vector;

class Lair: public Placeable {
protected:
    vector<int, Entity> queue;

public:
    void resetQueue(vector<int, Entity> newQueue);
    void increaseSpeed(int coef);
    void addToQueue(Entity);
    void tick();
};

#endif
