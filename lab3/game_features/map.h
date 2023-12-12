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
    Matrix<Tile> tiles; // Stores tiles types
    Coordinates castlePos{};
    Castle castle;
    vector<Coordinates> lairs;
    unsigned width{}, height{};

    void calculateRoutes();

public:
    Map(Matrix<TileType> map, Coordinates castleCoords, const vector<Coordinates>& lairsPos);

    unsigned getWidth() const { return width; };

    unsigned getHeight() const { return height; };

    Coordinates getCastleCoords() const {return castlePos;};

    Castle &getCastle() {return castle;};

    void printMap() const;

    bool isAccurate();

    void replan(Matrix<Tile>& newTilesList) {
        tiles = newTilesList;
        width = tiles.getWidth();
        height = tiles.getHeight();
    };

    Tile *getTile(int x, int y);
    Tile *getTile(Coordinates coordinates);
};

#endif //OOPCPP_MAP_H
