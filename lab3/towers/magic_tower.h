
#ifndef LAB3_MAGIC_TOWER_H
#define LAB3_MAGIC_TOWER_H


#include "tower.h"
#include "entity.h"

class MagicTower: public Tower {
protected:
    MagicTower() {}

    void applyRandomEffect(Entity *target);

};

#endif //LAB3_MAGIC_TOWER_H
