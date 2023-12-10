#ifndef OOPCPP_ENTITY_H
#define OOPCPP_ENTITY_H

#include "../effects/effect.h"
#include "../objects/sprite.h"
#include "../utility/coords.h"
#include "../utility/path.h"
#include <vector>
#include <unordered_map>
#include "castle.h"

class Entity : public Sprite {
protected:
    unsigned level;
    unsigned hp;
    double damagePerTick;
    bool isSpawned = false;
    double speed; // tiles per tick
    double tilesPassed{};
    std::vector<Effect> activeEffects;
    unsigned deathCost;
    bool atCastle = false;
    Path path;
    unsigned positionAtPath = -1;

    virtual bool isImmuneTo(const Effect &effect) { return false;};
public:
    explicit Entity(unsigned int hp = 100, int dpt = 100, unsigned int speed = 1, unsigned int deathCost = 10,
                    unsigned int level = 0) : Sprite(-1, -1, 0),
                                    level(level), hp(hp), damagePerTick(dpt), speed(speed),
                                    deathCost(deathCost) {};

    unsigned getDeathCost() const {return deathCost;};

    void move(Castle &castle);

    void useEffects();

    void spawn(Path lairPath);

    void getEffect(Effect newEffect);

    void receiveDamage(int amount);

    unsigned getHPAmount() const;

    bool isAlive() const;

    friend class Effect;
};

class Zombie : public Entity {
public:
    explicit Zombie(): Entity() {};
    bool isImmuneTo(const Effect &effect) override {
        switch (effect.effectType) {
            case Slowness:
                break;
            case Fatigue:
                break;
            case Poison:
                return true;
        }
        return false;
    }
};

class JetpackZombie : public Zombie {
public:
    JetpackZombie(): Zombie(){};
};

#endif //OOPCPP_ENTITY_H
