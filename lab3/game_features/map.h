#ifndef OOPCPP_MAP_H
#define OOPCPP_MAP_H

#include <vector>
#include "../objects/tile.h"

class Map {
protected:
    std::vector<std::vector<Tile>> tiles;
public:
    const unsigned width, height;
    bool isAccurate();
    void replan(std::vector<std::vector<Tile>> newTilesList);
};

#endif //OOPCPP_MAP_H
