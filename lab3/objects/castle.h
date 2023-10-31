
#ifndef OOPCPP_CASTLE_H
#define OOPCPP_CASTLE_H

#include "placeable.h"

class Castle: public Placeable {
protected:
    int hp;
public:
    void receiveDamage(int amount);
    int getHP() {return hp};
};


#endif
