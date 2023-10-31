#ifndef OOPCPP_GAME_H
#define OOPCPP_GAME_H


#include "map.h"
class Game {
protected:
    void moveEntities();
    void useDefence();
public:
    void process();
    void place(Placeable *newObject);
};

#endif //OOPCPP_GAME_H
