
#ifndef LAB3_TOWER_STRATEGIES_H
#define LAB3_TOWER_STRATEGIES_H

#include "entity.h"
#include "../effects/effect.h"
#include "defence.h"

enum AttackStrategy {
    ClosestToCastle,
    ClosestToSelf,
    Fastest,
    Slowest,
    WithMostHP,
    WithMostDMG
};
#endif //LAB3_TOWER_STRATEGIES_H
