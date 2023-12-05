
#ifndef OOPCPP_TILE_H
#define OOPCPP_TILE_H

#include "../utility/coords.h"
#include "../objects/sprite.h"
#include "../objects/placeable.h"
#include "sprite.h"
#include "tile_type.h"

class Tile : public Sprite {
protected:
    Placeable *contents = nullptr;
public:
    Placeable *getContents() const {
        return contents;
    }

    void setContents(Placeable *contents) {
        Tile::contents = contents;
    }

protected:
    TileType tileType;
public:

    TileType getType() const {
        return tileType;
    };

    Tile(Coordinates coords, TileType type) : Sprite(coords, 0), tileType(type) {};
};


#endif
