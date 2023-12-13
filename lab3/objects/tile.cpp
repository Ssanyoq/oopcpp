#include "tile.h"


void Tile::setContents(Placeable *contents) {
    Tile::contents = contents;
    Tile::contents->setPos(position);
}