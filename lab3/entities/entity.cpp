#include "entity.h"

#include <utility>

void Entity::useEffects() {
    for (int i = 0; i < activeEffects.size(); i++) { // FIXME
        auto effectNumbers = activeEffects[i].dealEffect();

        receiveDamage(effectNumbers[HealthDecrease]);
        speed *= effectNumbers[Speed];
        damagePerTick *= effectNumbers[DamageDecrease];
        if (!activeEffects[i].isActive()) {
            activeEffects.erase(activeEffects.begin() + i);
        }
    }
}

void Entity::spawn(Path lairPath) {
    isSpawned = true;
    path = std::move(lairPath);
    position = path[0];
    positionAtPath = 0;
}

void Entity::move(Castle &castle) {
    if (!isSpawned) { return;}
    if (!isAlive()) { return;}
    if (positionAtPath != path.size() - 1) {
        tilesPassed += speed;

        positionAtPath += (int)tilesPassed;
        tilesPassed -= (int)tilesPassed;

        if (positionAtPath >= path.size()) {
            positionAtPath = path.size() - 1;
        }
        position = path[positionAtPath];
        return;
    }
    deathCost = 0;
    castle.receiveDamage((int)damagePerTick);

}

void Entity::getEffect(Effect newEffect) {
    activeEffects.push_back(newEffect);
}

unsigned int Entity::getHPAmount() const {
    if (hp < 0) {
        return 0;
    }
        return hp;
}

bool Entity::isAlive() const {
    return hp > 0;
}

void Entity::receiveDamage(int amount) {
    if (amount >= hp) {
        hp = 0;
    } else {
        hp -= amount;
    }
}

