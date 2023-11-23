#ifndef OOPCPP_TOWER_H
#define OOPCPP_TOWER_H

#include "defence.h"
#include "../effects/effect.h"

    enum AttackStrategy {
    ClosestToCastle,
    ClosestToSelf,
    Fastest,
    Slowest,
    WithMostHP,
    WithMostDMG
};

class Tower : public Defence {
protected:
    int dps;
    unsigned bulletSpeed;
    unsigned fireRate;
    unsigned penetration;
    AttackStrategy strategy;

    Tower(const Game &currentGame, const Tile &tile, AttackStrategy strat) {
        Defence(Game, tile)
    }
    Entity *pickTarget();
    // ..........

public:
    void shoot();
    void setStrat(AttackStrategy newStrat);

};

class MagicTower: public Tower {
protected:
    void applyRandomEffect(Entity *target);

};

#endif //OOPCPP_TOWER_H
