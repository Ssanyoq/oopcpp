#include "design.h"

std::pair<float, float> centeredCoords(unsigned objectWidth, unsigned objectHeight, unsigned screenWidth,
                                       unsigned screenHeight) {
    return {screenWidth / 2 - objectWidth / 2, screenHeight / 2 - objectHeight / 2};
}

std::pair<float, float>
bottomCoords(unsigned int objectWidth, unsigned int objectHeight, unsigned int screenWidth, unsigned int screenHeight) {
    return {screenWidth / 2 - objectWidth / 2, screenHeight - objectHeight};
}

bool isIntersecting(float x1, float y1, float x2, float y2, float w1, float h1) {
    return ((x2 >= x1 && x2 <= x1 + w1) && (y2 >= y1 && y2 <= y1 + h1));
}

Coordinates getTileByCoords(float x, float y, unsigned int mapWidth, unsigned int mapHeight, unsigned int screedWidth,
                            unsigned int screenHeight, unsigned int tileSize) {
    auto baseCoords = centeredCoords(tileSize * mapWidth,
                                     tileSize * mapHeight, screedWidth, screenHeight);
    auto relativeX = x - baseCoords.first;
    auto relativeY = y - baseCoords.second;

    return {.x = static_cast<long long>(relativeX / tileSize), .y = static_cast<long long>(relativeY / tileSize)};
}
