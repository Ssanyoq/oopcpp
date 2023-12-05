#include "map.h"
#include "../utility/warning.h"


Map::Map(vector<vector<TileType>> map, Coordinates castleCoords, const vector<Coordinates>& lairsPos):
        castle(100, castleCoords.x, castleCoords.y)
    {
    tiles = vector<vector<Tile>>(map.size(), vector<Tile>(map[0].size(),
                                                          Tile(Coordinates{.x = -1, .y = -1}, Road)));

    for (int i = 0; i < tiles.size(); i++) {
        for (int j = 0; j < tiles[i].size(); j++) {
            tiles[i][j] = Tile(Coordinates{.x = j, .y = i}, map[i][j]);
        }
    }
    height = map.size();
    width = map[0].size();
    tiles[castleCoords.y][castleCoords.x].setContents(&castle);

    for (int i = 0; i < lairsPos.size(); i++) {
        auto x = lairsPos[i].x, y = lairsPos[i].y;
        if (x >= width || y >= height ||
        x < 0 || y < 0) {
            warn("Lair's coordinates are out of range, Skipped");
            continue;
        }
        if (tiles[y][x].getContents() != nullptr) {
            warn("Castle is placed at this place, can't place lairs");
            continue;
        }
        Lair newLair(x, y);
        lairs.emplace_back(lairsPos[i]);
        tiles[y][x].setContents(&(newLair));
    }

    calculateRoutes();
}

void Map::printMap() const {
    for (int i = 0; i < tiles.size(); i++) {
        for (int j = 0; j < tiles[i].size(); j++) {
            if (castlePos.x == j && castlePos.y == i) {
                cout << "C";
                continue;
            }
            bool isLair = false;
            for (int k = 0; k < lairs.size(); k++) {
                if (lairs[k].x == j && lairs[k].y == i) {
                    cout << "L";
                    isLair = true;
                    break;
                }
            }
            if (isLair) {
                continue;
            }
            if (tiles[i][j].getContents() != nullptr) {
                cout << "P";
                continue;
            }
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
            types[i][j] = getTile(j, i)->getType(); // TODO
        }
    }
    auto distances = getDistances(types, castlePos);
    for (auto & lair : lairs) {

        (*dynamic_cast<Lair *>((tiles[lair.y][lair.x].getContents()))).setPath(getPath(distances, lair));
    }
}

bool Map::isAccurate() {
    if (tiles.size() != height) {
        return false;
    }
    for (int i = 0; i < tiles.size(); i++) {
        if (tiles[i].size() != width) {
            return false;
        }
    }
    for (auto & lair : lairs) {
        if (dynamic_cast<Lair *>((tiles[lair.y][lair.x].getContents()))->getPath().empty()) {
            return false;
        }
    }
    return true;
}

Tile *Map::getTile(int x, int y) {
    if (tiles.size() > x) {
        if (tiles[x].size() > y) {
            return &(tiles[x][y]);
        }
    }
    throw std::out_of_range("Tile with this index is yet to be defined");
}

Tile * Map::getTile(Coordinates coordinates) {
    return getTile(coordinates.x, coordinates.y);
}