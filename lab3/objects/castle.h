
#ifndef OOPCPP_CASTLE_H
#define OOPCPP_CASTLE_H

#include "placeable.h"

class Castle: public Placeable {
protected:
    unsigned hp;
    unsigned maxHp;
public:
    Castle(unsigned hp, int x, int y) : hp(hp), maxHp(hp), Placeable(0, 0, 0) {};
    void receiveDamage(int amount);
    int getHP() const {return hp;};
    bool isDead() const;
    int getMaxHp() const {return maxHp;};
    ObjectType getType() const override {return Base;};
};


#endif
