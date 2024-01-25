#include "closest_enemy.h"
#include "functions.h"

int findClosestEntity(Coordinates from, vector<Entity> entities) {
    if (entities.empty()) {
        return -1;
    }
    int closestInd = 0;
    auto closestDistance = getDistance(from, entities[0].getPos());
    for (int i = 1; i < entities.size(); i++) {
        auto curDistance = getDistance(from, entities[i].getPos());
        if (curDistance < closestDistance) {
            closestDistance = curDistance;
            closestInd = i;
        }
    }
    return closestInd;
}


