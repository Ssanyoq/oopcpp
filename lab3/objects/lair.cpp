#include "lair.h"

#include <utility>
#include "../utility/warning.h"

void Lair::doAction(std::vector<Entity> &entities) {
    tick();
//    warn("Nothing happened, use tick() method to progress!");
}

void Lair::resetQueue(LairQueue newQueue) {
    queue = std::move(newQueue);
    for (int i = 1; i < queue.size(); i++) {
        if (queue[i].second == 0) {
            queue[i].second = 1;
        }
        queue[i].second += queue[i - 1].second;
    }
    ticks = 0;
    currentIndex = 0;
}

void Lair::addToQueue(const Entity& newEntity, unsigned delay) {
    queue.emplace_back(pair<Entity, int>(newEntity, delay));
    if (queue.size() > 1) {
        queue[queue.size() - 1].second += queue[queue.size() - 2].second;
    }
}

void Lair::tick() {
    ticks++;
    if (queue.empty()) {
        return;
    }
    if (queue[currentIndex].second == ticks) {
        queue[currentIndex].first.spawn(pathToCastle);
        newEntity = &queue[currentIndex].first;
        currentIndex++;
    }
}



void Lair::setPath(Path newPath) {
    pathToCastle = std::move(newPath);
}

const LairQueue &Lair::getQueue() const {
    return queue;
}

Entity *Lair::getNewEntity() {
    if (newEntity != nullptr) {
        auto copy = newEntity;
        newEntity = nullptr;
        return copy;
    }
    return nullptr;
}