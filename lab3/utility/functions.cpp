#include "functions.h"
#include <iostream>


inline double getDistance(const Coordinates &first, const Coordinates &second) {
    return sqrt(pow(first.x - second.x, 2) +
                pow(first.y - second.y, 2));
}

double getDistance(const Sprite &first, const Sprite &second) {
    return getDistance(first.getPos(), second.getPos());
}

double calculateAngle(const Coordinates &from, const Coordinates &to) {
    return atan2(to.y - from.y, to.x - from.x);
}

Path getPath(const vector<vector<int>> &distances, Coordinates from) {
    int deltaY[] = {-1, 0, 1, 0};
    int deltaX[] = {0, 1, 0, -1};
    Path path; // from coordinates of point "from"
    auto curNum = distances[from.y][from.x];
    auto curCoords = from;
    path.push_back(from);

    while (curNum != 0) {
        int minDist = -1;
        Coordinates minCoords;
        for (int i = 0; i < 4; i++) {
            auto newCoords = curCoords;
            newCoords.x += deltaX[i];
            newCoords.y += deltaY[i];
            if (newCoords.y >= distances.size() || newCoords.y < 0 ||
                newCoords.x >= distances[0].size() || newCoords.x < 0 || distances[newCoords.y][newCoords.x] == -1
                    ) {
                continue;
            }
            auto newNum = distances[newCoords.y][newCoords.x];
            if (minDist == -1 || minDist > newNum) {
                minDist = newNum;
                minCoords = newCoords;
            }
        }
        curNum = minDist;
        curCoords = minCoords;
        path.push_back(curCoords);
    }
    path.pop_back(); // so that castle won't be a part of this path
//    if (path.size() == 1) {
//        path = Path(0);
//    }
    return path;
}

vector<vector<int>> getDistances(vector<vector<TileType>> map, const Coordinates &from) {
    int deltaY[] = {-1, 0, 1, 0};
    int deltaX[] = {0, 1, 0, -1};
    auto height = map.size(), width = map[0].size();
    vector<vector<int>> distances(height, vector<int>(width, 0));
    // x - width, y - height, so distances[y][x]
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j] != Road) {
                distances[i][j] = -1;
            }
        }
    }

    queue<Coordinates> traversalQueue;
    traversalQueue.push(from);

    while (!traversalQueue.empty()) {
        auto current = traversalQueue.front();
        int minNeighbor = -1;
        for (int i = 0; i < 4; i++) {
            // generating new coordinates
            auto newCoords = current;
            newCoords.x += deltaX[i];
            newCoords.y += deltaY[i];

            // Checking if there is obstacle or if they are out of bounds
            if (newCoords.x >= width || newCoords.x < 0 || newCoords.y >= height || newCoords.y < 0 ||
                distances[newCoords.y][newCoords.x] == -1) {
                continue;
            }

            // Making new number for this cell if neighbor was checked already
            if (distances[newCoords.y][newCoords.x] != 0 || (newCoords.x == from.x && newCoords.y == from.y)) {
                if (minNeighbor == -1 || minNeighbor > distances[newCoords.y][newCoords.x]) {
                    minNeighbor = distances[newCoords.y][newCoords.x];
                }
            } else {
                traversalQueue.push(newCoords);
            }
        }

        distances[current.y][current.x] = minNeighbor + 1;
        traversalQueue.pop();
    }

    return distances;
}