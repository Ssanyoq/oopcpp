#ifndef OOPCPP_TOWER_H
#define OOPCPP_TOWER_H

#include "defence.h"
#include "effect.h"
#include "tower_strategies.h"

class Entity;

class Tower : public Defence {
protected:
    int damagePerShot;
    AttackStrategy strategy;
    int cooldown = 0;
    unsigned cooldownDuration = 10;
public:
    void shoot(std::vector<Entity> &entities);
    void setStrategy(AttackStrategy strategy);
    void doAction(std::vector<Entity> &entities) override;

    ObjectType getType() const override; // TODO

    Tower(ll x, ll y, int dps=100, AttackStrategy strat = ClosestToSelf, int range=5) :
            Defence(x, y, 0, range),
            damagePerShot(dps), strategy(strat) {}
};

//class MagicTower: public Tower {
//protected:
//    MagicTower() {}
//
//    void applyRandomEffect(Entity *target);
//
//};

#endif //OOPCPP_TOWER_H
