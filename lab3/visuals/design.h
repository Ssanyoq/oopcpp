#ifndef LAB3_DESIGN_H
#define LAB3_DESIGN_H
//
#include <utility>
#include "../utility/coords.h"

#define TILE_SIZE 50

//#include <SFML/Graphics.hpp>
std::pair<float, float> centeredCoords(unsigned objectWidth, unsigned objectHeight, unsigned screenWidth = 1280,
                                       unsigned screenHeight = 720);


std::pair<float, float> bottomCoords(unsigned objectWidth, unsigned objectHeight, unsigned screenWidth = 1280,
                                     unsigned screenHeight = 720);

bool isIntersecting(float x1, float y1, float x2, float y2, float w1, float h1);

Coordinates getTileByCoords(float x, float y, unsigned mapWidth, unsigned mapHeight, unsigned screedWidth = 1280,
                            unsigned screenHeight = 720, unsigned tileSize = TILE_SIZE);


#endif //LAB3_DESIGN_H
