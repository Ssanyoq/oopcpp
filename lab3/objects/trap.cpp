#include "trap.h"

#include <utility>
#include "../utility/functions.h"


void Trap::dealEffect(std::vector<Entity> &entities) {
    if (cooldown != 0) {
        return;
    }
    auto target = findClosestEntity(position, entities);
    entities[target].getEffect(effect);
    cooldown = cooldownDuration;
}

void Trap::doAction(vector<Entity> &entities) {
    if (cooldown != 0) {
        cooldown--;
        return;
    }
    dealEffect(entities);
}
