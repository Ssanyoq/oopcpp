#ifndef OOPCPP_DEFENCE_H
#define OOPCPP_DEFENCE_H

#include "placeable.h"

class Defence : public Placeable {
protected:
    unsigned currentLevel;
    unsigned range;
public:
    Defence(const Game &currentGame, long long int x,
            long long int y, short rotation) : range(0), currentLevel(1), Placeable(currentGame, x, y, rotation) {};

    static bool isActive() { return false; };

    bool isPlaceableOn(const Tile &tile) const { return false; };

    void upgrade() {};
};

#endif //OOPCPP_DEFENCE_H
