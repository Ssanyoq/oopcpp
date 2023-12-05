#ifndef OOPCPP_TRAP_H
#define OOPCPP_TRAP_H

#include "defence.h"
#include "../effects/effect.h"


class Trap : public Defence {
protected:
    static const unsigned cooldownDuration = 10;
    Effect effect;
    unsigned cooldown;
public:
    Trap(EffectType effect, ll x = 0, ll y = 0, short rotation = 0,
    unsigned int effectDuration = 10
    ) :
    Defence(x, y, rotation),
    effect(effect, effectDuration) {}

    void dealEffect(std::vector<Entity> entities);

    void doAction(std::vector<Entity> &entities);

    bool isActive() { return true; };
};

#endif //OOPCPP_TRAP_H
