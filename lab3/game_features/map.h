#ifndef OOPCPP_MAP_H
#define OOPCPP_MAP_H

#include <utility>
#include <vector>
#include <iostream>

using std::cout;
using std::vector;

#include "../objects/tile.h"
#include "../objects/castle.h"
#include "../utility/matrix.h"
#include "../utility/functions.h"
#include "tile_type.h"
#include "lair.h"

class Lair;

class Map {
protected:
    vector<vector<Tile>> tiles;
    Coordinates castlePos{};
    vector<pair<Coordinates, Lair>> lairs;
    unsigned width{}, height{};
    vector<vector<Lair>> routes;


    void calculateRoutes();

public:
    Map(vector<vector<TileType>> map, Coordinates castle, const vector<Coordinates>& lairsPos);

    unsigned getWidth() const { return width; };

    unsigned getHeight() const { return height; };

    Coordinates getCastle() const {return castlePos;};

    void printMap() const;

    bool isAccurate();

    void replan(std::vector<std::vector<Tile>> newTilesList) {
        tiles = std::move(newTilesList);
        width = tiles.size();
        height = tiles[0].size();
    };

    Tile getTile(int x, int y) const;
    Tile getTile(Coordinates coordinates) const;
};

#endif //OOPCPP_MAP_H
