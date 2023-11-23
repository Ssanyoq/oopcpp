#ifndef OOPCPP_MAP_H
#define OOPCPP_MAP_H

#include <utility>
#include <vector>
using std::vector;
#include "../objects/tile.h"
#include "../objects/castle.h"
#include "../objects/lair.h"

class Map {
protected:
    vector<vector<Tile>> tiles;
    Castle *castle;
    vector<Lair> lairs;
    unsigned width, height;
    vector<vector<Coordinates>> routes;


    void calculateRoutes();
public:
    unsigned getWidth() const {return width;};
    unsigned getHeight() const {return height;};

    Map(unsigned width, unsigned height): width(width), height(height), castle(){};
    Map(vector<vector<Tile>> tiles);
    bool isAccurate();
    void replan(std::vector<std::vector<Tile>> newTilesList) { tiles = std::move(newTilesList);
        width = tiles.size(); height = tiles[0].size();};
    Tile *getTile(int x, int y) const;
};

#endif //OOPCPP_MAP_H
