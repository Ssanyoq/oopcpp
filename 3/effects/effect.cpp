#include "effect.h"
#include "../utility/warning.h"

std::unordered_map<EntityStats, double> Effect::dealEffect() {
    std::unordered_map<EntityStats, double> coefs;
    if (ticksLeft < 0) {
        return coefs;
    }
    coefs[Speed] = 1;
    coefs[DamageDecrease] = 1;
    coefs[HealthDecrease] = 0;
    switch (effectType) {
        case Slowness:
            if (isFresh) {
                coefs[Speed] = 0.4;
            }
            if (ticksLeft == 0) {
                coefs[Speed] = 1 / 0.4;
            }
            break;
        case Fatigue:
            if (isFresh) {
                coefs[DamageDecrease] = 0.5;
            }
            if (ticksLeft == 0) {
                coefs[DamageDecrease] = 2;
            }
            break;
        case Poison:
            coefs[HealthDecrease] = 10;
            break;
        default: {
            warn("Effect of given type is not implemented yet!");
        }
    }
    isFresh = false;
    ticksLeft--;
    return coefs;
}

void Effect::operator=(const Effect& effect) {

}

//float aa() {
//    Effect a(Fatigue);
//    auto b = a.dealEffect();
//    auto c = b["damage"];
//}