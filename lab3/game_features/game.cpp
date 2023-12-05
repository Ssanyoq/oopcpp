#include "game.h"


Game::Game() = default;

void Game::addEntity(Entity& newEntity) {
    entities.push_back(newEntity);
}
void Game::addDefence(Defence &newDefence) {
    auto tile = currentMap.getTile(newDefence.getPos()); // TODO pointer
    if (tile->getContents() == nullptr) {
        tile->setContents((Placeable *) &newDefence);
    }
    placeables.push_back(newDefence);
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
    currentMap.getTile(placeables[index].getPos())->setContents(nullptr);
    placeables.erase(placeables.begin() + index);
}


void Game::moveEntities() {
    for (int i = 0; i < entities.size(); i++) {
        if (!entities[i].isAlive()) {
            deleteEntity(i);
        }
        entities[i].move(currentMap.getCastle());
    }
}
void Game::usePlaceables() {
    for (auto & placeable : placeables) {
        placeable.doAction();
    }
}

void Game::process() {
    usePlaceables();
    moveEntities();

}

bool Game::place(const Placeable& newObject, int x, int y) {
    placeables.push_back(newObject);
    return true; //TODO
}


