#include "lair.h"

#include <utility>
#include "../utility/warning.h"

void Lair::doAction() {
    warn("Nothing happened, use tick() method to progress!");
}

void Lair::resetQueue(LairQueue newQueue) {
    queue = std::move(newQueue);
    ticks = 0;
    currentIndex = 0;
}

void Lair::addToQueue(Entity newEntity, unsigned delay) {
    queue.emplace_back(pair<Entity, int>(newEntity, delay));
    if (queue.size() > 1) {
        queue[queue.size() - 1].second += queue[queue.size() - 2].second;
    }
}

void Lair::tick() {
    ticks++;
    if (queue[currentIndex].second == ticks) {
        queue[currentIndex].first.spawn(pathToCastle);
        currentIndex++;
    }
}

void Lair::setPath(Path newPath) {
    pathToCastle = std::move(newPath);
}

const LairQueue &Lair::getQueue() const {
    return queue;
}
