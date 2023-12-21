#ifndef OOPCPP_TRAP_H
#define OOPCPP_TRAP_H

#include "defence.h"
#include "../effects/effect.h"
#include "../utility/closest_enemy.h"


class Trap : public Defence {
protected:
    static const unsigned cooldownDuration = 120;
    Effect effect;
    unsigned cooldown = 0;
public:
    Trap(EffectType effect, ll x = 0, ll y = 0, short rotation = 0,
    unsigned int effectDuration = 100
    ) :
            Defence(x, y, rotation, 10),
    effect(effect, effectDuration) {}

    void dealEffect(std::vector<Entity> &entities);

//    bool isActive() const {return (cooldown == 0);};

    void doAction(std::vector<Entity> &entities) override;

    bool isActive() const { return (cooldown == 0);};

    ObjectType getType() const override;

};

#endif //OOPCPP_TRAP_H
