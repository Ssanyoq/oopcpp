//
// Created by Aleksandr Kutsalo on 21.11.2023.
//

#ifndef LAB3_FUNCTIONS_H
#define LAB3_FUNCTIONS_H

#include "../objects/sprite.h"
#include "coords.h"
#include <cmath>

double getSpriteDistance(const Sprite &first, const Sprite &second) {
    return sqrt(pow(first.getPos().x - second.getPos().x, 2) +
                pow(first.getPos().y - second.getPos().y, 2));
}
double getDistance(const Coordinates &first, const Coordinates &second) {
    return sqrt(pow(first.x - second.x, 2) +
                pow(first.y - second.y, 2));
}

double calculateAngle(const Coordinates &from, const Coordinates &to) {
    return atan2(to.y - from.y, to.x - from.x);
}


vector<Coordinates> getShortestPath(const Map &map, const Coordinates &first, const Coordinates &second) {
    vector<vector<bool>> visited;
    for (int i = 0; i < map.getHeight(); i++) {
        vector<bool> vect(map.getWidth(), false);
        visited.push_back(vect);
    }
    return vector<Coordinates>(1, Coordinates{.x = 0, .y = 0}); // TODO

}

#endif //LAB3_FUNCTIONS_H
