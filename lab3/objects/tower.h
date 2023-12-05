#ifndef OOPCPP_TOWER_H
#define OOPCPP_TOWER_H

#include "defence.h"
#include "../effects/effect.h"
#include "entity.h"

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
    int damagePerShot;
    AttackStrategy strategy;

    Tower(
            const Tile &tile, AttackStrategy strat, int dps = 100) :
            Defence(tile.getPos().x, tile.getPos().y, 0),
            damagePerShot(dps), strategy(strat) {}

public:
    void shoot(std::vector<Entity> entities); //
    void setStrat(AttackStrategy newStrat) { strategy = newStrat; };
    void doAction(std::vector<Entity> &entities);

};

//class MagicTower: public Tower {
//protected:
//    MagicTower() {}
//
//    void applyRandomEffect(Entity *target);
//
//};

#endif //OOPCPP_TOWER_H
