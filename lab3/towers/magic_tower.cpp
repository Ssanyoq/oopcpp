
#include "magic_tower.h"

void MagicTower::applyRandomEffect(Entity *target) {
    target->getEffect(Effect(Poison));
}

