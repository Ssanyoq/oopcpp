
#ifndef OOPCPP_TILE_H
#define OOPCPP_TILE_H

#include "placeable.h"
#include "sprite.h"

enum TileType {
    Road,
    Field,
    Forest
};

class Tile: public Sprite {
protected:
    Placeable *contents;
public:
    const TileType tileType;
    Placeable *getContents();
    void setContents(Placeable *newContents);
};


#endif //OOPCPP_TILE_H
