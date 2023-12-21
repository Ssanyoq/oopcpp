#include "trap.h"

#include <utility>
#include "../utility/functions.h"


void Trap::dealEffect(std::vector<Entity> &entities) {
    if (cooldown != 0) {
        return;
    }
    for (auto &entity:entities) {
        auto entityPos = entity.getPos();
        if (entityPos.x == position.x && entityPos.y == position.y) {
            entity.getEffect(effect);
            cooldown = cooldownDuration;
        }
    }
}

void Trap::doAction(vector<Entity> &entities) {
    if (cooldown != 0) {
        cooldown--;
        return;
    }
    dealEffect(entities);
}

ObjectType Trap::getType() const {
    return ObjectType::Danger;
}
