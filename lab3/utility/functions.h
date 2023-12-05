#ifndef LAB3_FUNCTIONS_H
#define LAB3_FUNCTIONS_H

#include "../objects/sprite.h"
#include "../objects/tile_type.h"
#include "path.h"

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

Path getPath(const vector<vector<int>>& distances, Coordinates from);

#endif //LAB3_FUNCTIONS_H
