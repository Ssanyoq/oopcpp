#include "game.h"

#include <utility>
#include "../utility/warning.h"


Game::Game() = default;

void Game::addEntity(Entity &newEntity) {
    entities.push_back(newEntity);
}

void Game::addDefence(Defence *newDefence) {
    auto tile = currentMap.getTile(newDefence->getPos());
    if (tile->getContents() == nullptr) {
        tile->setContents((Placeable *) newDefence);
        placeables.push_back(newDefence);
    } else {
        warn("Can't place defence here!");
    }
}

void Game::deleteEntity(int index) {
    if (index < 0 or index > entities.size() - 1) {
        throw std::out_of_range("Entity with this index does not exist");
    }
    entities.erase(entities.begin() + index);
}

void Game::deletePlaceable(int index) {
    if (index < 0 or index > placeables.size() - 1) {
        throw std::out_of_range("Object with this index does not exist");
    }
    currentMap.getTile(placeables[index]->getPos())->setContents(nullptr);
    placeables.erase(placeables.begin() + index);
}


void Game::moveEntities(int iterStart, int iterEnd) {
    if (iterEnd == -1 || iterEnd >= entities.size()) {
        iterEnd = entities.size() - 1;
    }
    for (int i = iterStart; i <= iterEnd; i++) {
        if (!entities[i].isAlive()) {
            deleteEntity(i);
        }
        entities[i].move(currentMap.getCastle());
        if (entities[i].isAlive() and entities[i].isAtCastle()) {
            entities[i].dealDamage(
                    dynamic_cast<Castle *>(currentMap.getTile(currentMap.getCastleCoords())->getContents()));
        }
    }
}

void Game::usePlaceables(int iterStart, int iterEnd) {
    if (iterEnd == -1 || iterEnd >= placeables.size()) {
        iterEnd = placeables.size() - 1;
    }
    for (int i = iterStart; i <= iterEnd; i++) {
        placeables[i]->doAction(entities);
    }
}

void Game::process() {
//  std::thread::hardware_concurrency() == 8 for Apple M1
    auto partsIndices = splitRange(placeables.size(), THREADS_TO_USE);
    vector<std::thread> threads;
    threads.reserve(partsIndices.size());
    for (int i = 0; i < partsIndices.size(); i++) {
        threads.emplace_back(&Game::usePlaceables, this, partsIndices[i].first, partsIndices[i].second);
    }
    for (int i = 0; i < partsIndices.size(); i++) {
        threads[i].join();
    }
    usePlaceables();

    // Add entities from lairs to processing queue
    auto newEntities = currentMap.getNewEntities();
    if (!newEntities.empty()) {
        entities.insert(entities.end(), newEntities.begin(), newEntities.end());
    }

    partsIndices = splitRange(entities.size(), THREADS_TO_USE);
    vector<std::thread> entityThreads;
    entityThreads.reserve(partsIndices.size());

    for (int i = 0; i < partsIndices.size(); i++) {
        entityThreads.emplace_back(&Game::moveEntities, this, partsIndices[i].first, partsIndices[i].second);
    }
    for (int i = 0; i < partsIndices.size(); i++) {
        entityThreads[i].join();
    }
    moveEntities(0, -1);
}


Map &Game::getCurrentMap() {
    return currentMap;
}


void Game::changeMap(Map newMap) {
    entities = {};
    placeables = {};
    currentMap = std::move(newMap);
    for (int y = 0; y < currentMap.getHeight(); y++) {
        for (int x = 0; x < currentMap.getWidth(); x++) {
            auto contents = currentMap.getTile(x, y)->getContents();
            if (contents != nullptr) {
                placeables.emplace_back(contents);
            }
        }
    }
}


