#ifndef OOPCPP_DEFENCE_H
#define OOPCPP_DEFENCE_H

#include "placeable.h"
#include "tile.h"
#include "entity.h"

class Defence : public Placeable {
protected:
    unsigned currentLevel;
    unsigned range;
public:
    Defence(long long int x,
            long long int y, short rotation) : range(0), currentLevel(1), Placeable(x, y, rotation) {};

    static bool isActive() { return false; };

    bool isPlaceableOn(const Tile &tile) const { return false; };

    void upgrade() {};

    virtual void doAction(std::vector<Entity> &entities)=0;
};

#endif //OOPCPP_DEFENCE_H
