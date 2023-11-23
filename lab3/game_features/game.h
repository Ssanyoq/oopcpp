#ifndef OOPCPP_GAME_H
#define OOPCPP_GAME_H

#include "map.h"
#include <vector>
#include "../entities/entity.h"
#include "../objects/placeable.h"

class Game {
protected:
    std::vector<Entity> entities;
    std::vector<Placeable> placeables;
    Map currentMap;
    void moveEntities();
    void usePlaceables();

    void addEntity(const Entity& newEntity);
    void addPlaceable(const Placeable &newPlaceable);
    void deleteEntity(int index);
    void deletePlaceable(int index);
public:
    Game();
    void process();
    bool place(Placeable *newObject, int x, int y);
};

#endif //OOPCPP_GAME_H
