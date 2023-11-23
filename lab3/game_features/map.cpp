#include "map.h"



void Map::calculateRoutes() {

}

Map::Map(vector<vector<Tile>> tiles) {
    height = tiles.size();
    width = tiles[0].size();
    this->tiles = tiles;
}

bool Map::isAccurate() {
    if (tiles.size() != height) {
        return false;
    }
    for (int i = 0; i < tiles.size(); i++) {
        if (tiles[i].size() != width) {
            return false;
        }
        for (int j = 0; j < tiles[i].size(); j++) {

        }
    }
}

Tile *Map::getTile(int x, int y) const {
    if (tiles.size() > x) {
        if (tiles[x].size() > y) {
            return &(tiles[x][y]);
        }
    }
    throw std::out_of_range("Tile with this index is yet to be defined");
}