#ifndef OOPCPP_DEFENCE_H
#define OOPCPP_DEFENCE_H

#include "placeable.h"

class Defence: public Placeable {
protected:
    unsigned currentLevel;
    unsigned range;
public:
    bool isActive() const;
    bool isPlaceableOn(const Tile &tile) const;
    void upgrade(Game &game);

};

#endif //OOPCPP_DEFENCE_H
