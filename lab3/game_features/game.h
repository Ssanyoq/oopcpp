#ifndef OOPCPP_GAME_H
#define OOPCPP_GAME_H

#include "map.h"
#include <vector>
#include "defence.h"
#include "../entities/entity.h"
#include "../objects/placeable.h"

class Game {
protected:
    void moveEntities();
    void usePlaceables();
    void addEntity( Entity& newEntity);
    void addDefence( Defence &newDefence); // TODO
    void deleteEntity(int index);
    void deletePlaceable(int index);
public:
    std::vector<Entity> entities;
    std::vector<Placeable> placeables;
    Map currentMap = Map({{Road}}, {.x = 0, .y = 0}, {});
    Game();
    void process();
    bool place(const Placeable &newObject, int x, int y);
};

#endif //OOPCPP_GAME_H
