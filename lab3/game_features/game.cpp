#include "game.h"

Game::Game() {

}

void Game::addEntity(const Entity& newEntity) {
    entities.push_back(newEntity);
}
void Game::addPlaceable(const Placeable &newPlaceable) {
    placeables.push_back(newPlaceable);
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
    placeables.erase(placeables.begin() + index);
}


void Game::moveEntities() {
    for (int i = 0; i < entities.size(); i++) {
        entities[i].move();
        if (!entities[i].isAlive()) {
            deleteEntity(i);
        }
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

bool Game::place(Placeable *newObject, int x, int y) {
    Tile tile = currentMap.getTile(x, y);
    if (tile.getContents() == nullptr) {
        tile.setContents(newObject);
        return true;
    }
    return false;
}


