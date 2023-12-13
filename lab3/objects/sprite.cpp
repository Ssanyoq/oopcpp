#include "sprite.h"

void Sprite::changeVisibility(bool isInvisible) {
    this->invisible = isInvisible;
}

Coordinates Sprite::setPos(Coordinates newPosition) {
    position = newPosition;
}
