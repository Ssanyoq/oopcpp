#include "map.h"
#include "../utility/warning.h"


Map::Map(vector<vector<TileType>> map, Coordinates castle, const vector<Coordinates>& lairsPos) {
    tiles = vector<vector<Tile>>(map.size(), vector<Tile>(map[0].size(),
                                                          Tile(Coordinates{.x = -1, .y = -1}, Road)));

    for (int i = 0; i < tiles.size(); i++) {
        for (int j = 0; j < tiles[i].size(); j++) {
            tiles[i][j] = Tile(Coordinates{.x = j, .y = i}, map[i][j]);
        }
    }
    height = map.size();
    width = map[0].size();

    for (int i = 0; i < lairsPos.size(); i++) {
        auto x = lairsPos[i].x, y = lairsPos[i].y;
        if (x >= width || y >= height ||
        x < 0 || y < 0) {
            warn("Lair's coordinates are out of range, Skipped");
            continue;
        }
        lairs.emplace_back(lairsPos[i], Lair(x, y));
    }
}

void Map::printMap() const {
    for (int i = 0; i < tiles.size(); i++) {
        for (int j = 0; j < tiles[i].size(); j++) {
            switch (tiles[i][j].getType()) {
                case Road:
                    cout << ".";
                    break;
                case Field:
                    cout << "#";
                    break;
                case Forest:
                    cout << "÷";
                    break;

            }
        }
        cout << std::endl;
    }
}

void Map::calculateRoutes() {
    vector<vector<TileType>> types(height, vector<TileType>(width, Road));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            types[i][j] = getTile(j, i).getType();
        }
    }
    auto distances = getDistances(types, castlePos);

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
    return true;
}

Tile Map::getTile(int x, int y) const {
    if (tiles.size() > x) {
        if (tiles[x].size() > y) {
            return (tiles[x][y]);
        }
    }
    throw std::out_of_range("Tile with this index is yet to be defined");
}

Tile Map::getTile(Coordinates coordinates) const {
    return getTile(coordinates.x, coordinates.y);
}