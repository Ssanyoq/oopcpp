#ifndef OOPCPP_GAME_H
#define OOPCPP_GAME_H

#include "map.h"
#include <vector>
#include "defence.h"
#include "../entities/entity.h"
#include "../objects/placeable.h"
#include <thread>

#define THREADS_TO_USE 10

class Game {
protected:
    void moveEntities(int iterStart, int iterEnd);
    void usePlaceables(int iterStart=0, int iterEnd=-1);
    Map currentMap = Map(Matrix<TileType>({{Road}}), {.x = 0, .y = 0}, {});
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
