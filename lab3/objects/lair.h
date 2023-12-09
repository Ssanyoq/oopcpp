#ifndef OOPCPP_LAIR_H
#define OOPCPP_LAIR_H

#include "placeable.h"
#include <vector>
#include "../entities/entity.h"
#include "../utility/path.h"
//#include "game.h"

class Entity; // TODO
class Game;

typedef std::vector<std::pair<Entity, unsigned>> LairQueue;
using std::vector;

//template <typename T>
//LairQueue generateQueue(unsigned amount, unsigned delay, unsigned delayFromStart=0) {
//    LairQueue out(amount);
//    for (int i = 0; i < amount; i++) {
//        out[i].second = i * delay + delayFromStart;
//        out[i].first = T();
//    }
//    return out;
//}

class Lair: public Placeable {
protected:
    LairQueue queue;
    Path pathToCastle;
    unsigned ticks = 0;
    unsigned currentIndex = 0;

public:
    Lair(): Placeable(-1, -1, 0), queue(), pathToCastle() {};
    Lair(long long int x, long long int y) : Placeable(x, y, 0), queue(), pathToCastle() {};
    void resetQueue(LairQueue newQueue);
    void addToQueue(Entity newEntity, unsigned delay=10);
    void doAction() override;
    void tick();
    void setPath(Path newPath);
    Path getPath() const { return pathToCastle;}
    const LairQueue &getQueue() const;

};

#endif
