
#ifndef OOPCPP_EFFECT_H
#define OOPCPP_EFFECT_H

#include "entity.h"

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
public:
    const EffectType effectType;

    explicit Effect(EffectType effect, unsigned ticks = 10) : effectType(effect), ticksLeft(ticks) {};

    void dealEffect(Entity *enemy);
};

#endif //OOPCPP_EFFECT_H
