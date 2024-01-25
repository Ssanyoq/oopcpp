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
    /**
     * Finds best entity from given vector and shoots according to strategy
     */
    void shoot(std::vector<Entity> &entities, unsigned (*pickStrategy)(std::vector<Entity>, Coordinates));


    void setStrategy(AttackStrategy strategy);

    /**
     * Uses shoot() method
     * @see Entity::shoot()
     */
    void doAction(std::vector<Entity> &entities) override;

    /**
     * Returns price of this object
     */
    unsigned getPrice() const override { return 35; };

    /**
     * Checks if given tile type is good for placing
     * @param tileType parameter of type TileType
     */
    bool isPlaceableOn(TileType tileType) const override { return (tileType == Field); };

    /**
     * Returns enum type of tower
     */
    ObjectType getType() const override; // TODO


    /**
     * Constructor
     * @param x where to place this tower
     * @param y
     * @param dps damage that this tower deals per tick(per call of doAction())
     * @param strat enum strategy of shooting
     * @param range how far this tower can shoot
     * @see Tower::shoot()
     */
    explicit Tower(ll x = -1, ll y = -1, int dps = 1, AttackStrategy strat = ClosestToSelf, int range = 5) :
            Defence(x, y, 0, range),
            damagePerShot(dps), strategy(strat) {};
};


#endif //OOPCPP_TOWER_H
