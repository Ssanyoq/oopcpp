#include "map.h"
#include "../utility/warning.h"


Map::Map(Matrix<TileType> map, Coordinates castleCoords, const vector<Coordinates>& lairsPos) :
        castle(100, castleCoords.x, castleCoords.y), tiles(map.getWidth(),
                                                           map.getHeight(),
                                                           Tile(Coordinates{.x=-1, .y=-1}, Forest))
    {
//    tiles(map.size(), vector<Tile>(map[0].size(),
//                                                          Tile(Coordinates{.x = -1, .y = -1}, Road)));

    for (int y = 0; y < tiles.getHeight(); y++) {
        for (int x = 0; x < tiles.getWidth(); x++) {
            tiles[y][x] = Tile(Coordinates{.x = x, .y = y}, map[y][x]);
        }
    }
    height = map.getHeight();
    width = map.getWidth();
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
        Lair *newLair = new Lair(x, y);
        lairs.emplace_back(lairsPos[i]);
        tiles[y][x].setContents(newLair);
    }

    calculateRoutes();
}

void Map::printMap() const {
    for (int y = 0; y < tiles.getHeight(); y++) { // y
        for (int x = 0; x < tiles.getWidth(); x++) { // x
            if (castlePos.x == x && castlePos.y == y) {
                cout << "C";
                continue;
            }
            bool isLair = false;
            for (int lairIndex = 0; lairIndex < lairs.size(); lairIndex++) {
                if (lairs[lairIndex].x == x && lairs[lairIndex].y == y) {
                    cout << "L";
                    isLair = true;
                    break;
                }
            }
            if (isLair) {
                continue;
            }
            if (tiles[Coordinates{.x=x,.y=y}].getContents() != nullptr) {
                cout << "P";
                continue;
            }
//            switch (this->getTile(x, y)->getType()) {
            switch (tiles[Coordinates{.x=x,.y=y}].getType()) {
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
        if (tiles.getWidth() != width) {
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
    if (tiles.getWidth() > x) {
        if (tiles.getHeight() > y) {
            return &(tiles[y][x]);
        }
    }
    throw std::out_of_range("Tile with this index is yet to be defined");
}

Tile * Map::getTile(Coordinates coordinates) {
    return getTile(coordinates.x, coordinates.y);
}