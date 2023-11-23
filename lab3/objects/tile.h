
#ifndef OOPCPP_TILE_H
#define OOPCPP_TILE_H

#include "../utitlity/coords.h"
#include "../objects/sprite.h"

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

    Tile(TileType type, Coordinates coords ): tileType(type){Sprite();};

    Placeable *getContents()const { return contents;};
    void setContents(Placeable *newContents) {contents = newContents;};
};


#endif
