#ifndef OOPCPP_ENTITY_H
#define OOPCPP_ENTITY_H

#include "../objects/sprite.h"
#include "../effects/effect.h"
#include "../objects/lair.h"
#include <vector>

class Entity: public Sprite {
protected:
    unsigned level;
    unsigned hp;
    int dps;
    unsigned hitsPerSecond;
    std::vector<Effect> activeEffects;
    unsigned deathCost;

    bool isImmuneTo(const Effect &effect);
public:
    unsigned getDeathCost();
    void spawn(const Lair &target);
    void move();
    void useEffects();
    void recieveDamage(int amount);
    unsigned getHPAmount();
};

class Zombie: public Entity {
public:
    Zombie();
};

class JetpackZombie: public Entity {
public:
    JetpackZombie();
};

#endif //OOPCPP_ENTITY_H
