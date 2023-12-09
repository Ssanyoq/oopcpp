#ifndef OOPCPP_MAP_H
#define OOPCPP_MAP_H

#include <utility>
#include <vector>
#include <iostream>

using std::cout;
using std::vector;

#include "../objects/tile.h"
#include "../objects/castle.h"
#include "../matrix/matrix.h"
#include "../utility/functions.h"
#include "tile_type.h"
#include "lair.h"

class Lair;

class Game;

class Map {
protected:
    vector<vector<Tile>> tiles; // Stores tiles types
    Coordinates castlePos{};
    Castle castle;
    vector<Coordinates> lairs;
    unsigned width{}, height{};

    void calculateRoutes();

public:
    Map(vector<vector<TileType>> map, Coordinates castleCoords, const vector<Coordinates>& lairsPos);

    unsigned getWidth() const { return width; };

    unsigned getHeight() const { return height; };

    Coordinates getCastleCoords() const {return castlePos;};

    Castle &getCastle() {return castle;};

    void printMap() const;

    bool isAccurate();

    void replan(std::vector<std::vector<Tile>> newTilesList) {
        tiles = std::move(newTilesList);
        width = tiles.size();
        height = tiles[0].size();
    };

    Tile *getTile(int x, int y);
    Tile *getTile(Coordinates coordinates);
};

#endif //OOPCPP_MAP_H
