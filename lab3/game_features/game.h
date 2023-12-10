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
    Map currentMap = Map({{Road}}, {.x = 0, .y = 0}, {});
    void deleteEntity(int index);
    void deletePlaceable(int index);
public:
    void addEntity( Entity& newEntity);
    void addDefence( Defence *newDefence);

    Map & getCurrentMap();

    void changeMap(Map newMap);
    std::vector<Entity> entities;
    std::vector<Placeable *> placeables;

    Game();
    void process();
};

#endif //OOPCPP_GAME_H
