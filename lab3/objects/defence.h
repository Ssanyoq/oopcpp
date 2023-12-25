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
    Defence(long long int x, long long int y, short rotation, unsigned range)
            : range(range), currentLevel(1), Placeable(x, y, rotation) {};

    bool isActive() { return true;};

    void upgrade() {};

    virtual unsigned getPrice() const {return 0;};

    virtual bool isPlaceableOn(TileType tileType) const {return true;};

    virtual void doAction(std::vector<Entity> &entities)=0;
};

#endif //OOPCPP_DEFENCE_H
