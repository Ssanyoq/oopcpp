#include "effect.h"
#include "../utitlity/warning.h"

void Effect::dealEffect(Entity *enemy) {
    for (int i = 0; i < enemy->activeEffects; i++) {
        if (enemy->activeEffects[i] == *this) {
        }
    }
    switch (effectType) {
        Slowness: {
            break;
        }
        default: {
            warn("Effect of given type is not implemented yet!");
        }
    }
}