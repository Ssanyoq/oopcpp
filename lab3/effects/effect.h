
#ifndef OOPCPP_EFFECT_H
#define OOPCPP_EFFECT_H

#include <unordered_map>
#include "../utility/entity_enum.h"


enum EffectType {
    Slowness,
    Fatigue,
    Poison,
    /*
    ...
    */
};

class Effect {
protected:
    unsigned ticksLeft;
    bool isFresh = true;
public:
    const EffectType effectType;

    explicit Effect(EffectType effect, unsigned ticks = 10) : effectType(effect), ticksLeft(ticks) {};

    void operator=(const Effect& effect);

    /**
     * @returns map with keys:
     *      speed
     *      damagePerTick
     *      damage
     */
    std::unordered_map<EntityStats, double> dealEffect();
    bool isActive() const {return ticksLeft >= 0;};
};

#endif
