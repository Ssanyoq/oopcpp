#include "tower.h"
#include "../utility/closest_enemy.h"
#include "../utility/functions.h"

void Tower::shoot(std::vector<Entity> &entities) {
    auto index = findClosestEntity(position, entities);
    auto distance = getDistance(position, entities[index].getPos());
    if (distance <= range) {

        // rotates tower
        rotationDegree = (short) calculateAngle(position, entities[index].getPos());

        entities[index].receiveDamage(damagePerShot);
    }
}

void Tower::doAction(std::vector<Entity> &entities) {
//    Defence::doAction(entities);
    shoot(entities);
}

void Tower::setStrategy(AttackStrategy strategy) {
    Tower::strategy = strategy;
}
