#include "tower.h"
#include "../utility/closest_enemy.h"
#include "../utility/functions.h"

unsigned pickClosestToSelf(std::vector<Entity> entities, Coordinates position) {
    return findClosestEntity(position, entities);
}

vector<unsigned> getInRange(std::vector<Entity> entities, Coordinates position, unsigned range) {
    vector<unsigned > out;
    for (int i = 0; i < entities.size(); i++) {
        if (getDistance(position, entities[i].getPos()) <= range) {
            out.push_back(i);
        }
    }
    return out;
}


void Tower::doAction(std::vector<Entity> &entities) {
//    Defence::doAction(entities);
    unsigned (*pickStrategy)(std::vector<Entity>, Coordinates) = pickClosestToSelf;
//    switch (strategy) {
//
//        case ClosestToCastle:
//            break;
//        case ClosestToSelf:
//            pickStrategy = pickClosestToSelf;
//            break;
//    }
    shoot(entities, pickStrategy);
}

void Tower::setStrategy(AttackStrategy strategy) {
    Tower::strategy = strategy;
}

ObjectType Tower::getType() const {
    return Turret;
}

void Tower::shoot(vector<Entity> &entities, unsigned (*pickStrategy)(std::vector<Entity>, Coordinates)) {
    if (cooldown != 0) {
        cooldown--;
        return;
    }
    if (entities.empty()) {
        rotationDegree += 10; // rotates if empty
        return;
    }
    auto index = pickStrategy(entities, position);
    auto distance = getDistance(position, entities[index].getPos());
    if (distance <= range) {
        // rotates tower
        rotationDegree = (short) calculateAngle(position, entities[index].getPos());

        entities[index].receiveDamage(damagePerShot);
        cooldown = cooldownDuration;
    } else {
        rotationDegree += 10;
    }
}
