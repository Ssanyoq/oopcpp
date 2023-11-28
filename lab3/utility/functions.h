//
// Created by Aleksandr Kutsalo on 21.11.2023.
//

#ifndef LAB3_FUNCTIONS_H
#define LAB3_FUNCTIONS_H

#include "../objects/sprite.h"
#include "../objects/tile_type.h"

#include "coords.h"
#include <cmath>
#include <vector>
#include <queue>

using std::queue;
using std::vector;


double getDistance(const Coordinates &first, const Coordinates &second);

double getDistance(const Sprite &first, const Sprite &second);

double calculateAngle(const Coordinates &from, const Coordinates &to);


vector<vector<int>> getDistances(vector<vector<TileType>> map, const Coordinates &from);

vector<Coordinates> getPath(const vector<vector<int>>& distances, int x, int y);

#endif //LAB3_FUNCTIONS_H
