#ifndef OOPCPP_TOWER_H
#define OOPCPP_TOWER_H

#include "defence.h"
#include "effect.h"
#include "tower_strategies.h"
#include "tile_type.h"

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
    static unsigned getPrice() {return 35;};

    bool isPlaceableOn(TileType tileType) const override {return (tileType == Field);};

    ObjectType getType() const override; // TODO


    Tower(ll x, ll y, int dps=1, AttackStrategy strat = ClosestToSelf, int range=5) :
            Defence(x, y, 0, range),
            damagePerShot(dps), strategy(strat) {};
};

//class MagicTower: public Tower {
//protected:
//    MagicTower() {}
//
//    void applyRandomEffect(Entity *target);
//
//};

#endif //OOPCPP_TOWER_H
