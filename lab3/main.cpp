#include <SFML/Graphics.hpp>
#include "game.h"
#include "visuals/design.h"
#include "matrix/matrix.h"
#include "tower.h"
#include "trap.h"

#define WIDTH 1280
#define HEIGHT 720
// HD 720p

sf::Font SVFont;


sf::Texture road, field, forrest, castle, towerBase, towerWeapon, zombie, lair,
        armedTrap, disarmedTrap, coin;

void loadTextures() {
    coin.loadFromFile(
            "/Users/ssanyoq/MEOW/2023f/oopcpp/lab3/game_files/textures/td_minimalist/towerDefense_tile272.png");
    forrest.loadFromFile(
            "/Users/ssanyoq/MEOW/2023f/oopcpp/lab3/game_files/textures/td_minimalist/towerDefense_tile024.png");
    field.loadFromFile(
            "/Users/ssanyoq/MEOW/2023f/oopcpp/lab3/game_files/textures/td_minimalist/towerDefense_tile050.png");
    road.loadFromFile(
            "/Users/ssanyoq/MEOW/2023f/oopcpp/lab3/game_files/textures/td_minimalist/towerDefense_tile159.png");
    castle.loadFromFile(
            "/Users/ssanyoq/MEOW/2023f/oopcpp/lab3/game_files/textures/td_minimalist/towerDefense_tile183.png");
    castle.setSmooth(true);
    towerBase.loadFromFile(
            "/Users/ssanyoq/MEOW/2023f/oopcpp/lab3/game_files/textures/td_minimalist/towerDefense_tile181.png");
    towerWeapon.loadFromFile(
            "/Users/ssanyoq/MEOW/2023f/oopcpp/lab3/game_files/textures/td_minimalist/towerDefense_tile204.png");
    towerWeapon.setSmooth(true);
    zombie.loadFromFile(
            "/Users/ssanyoq/MEOW/2023f/oopcpp/lab3/game_files/textures/td_minimalist/towerDefense_tile248.png");
    lair.loadFromFile(
            "/Users/ssanyoq/MEOW/2023f/oopcpp/lab3/game_files/textures/td_minimalist/towerDefense_tile269.png");
    armedTrap.loadFromFile(
            "/Users/ssanyoq/MEOW/2023f/oopcpp/lab3/game_files/textures/td_minimalist/towerDefense_tile131.png");
    disarmedTrap.loadFromFile(
            "/Users/ssanyoq/MEOW/2023f/oopcpp/lab3/game_files/textures/td_minimalist/towerDefense_tile021.png");

}

void drawGUI(Game &game, sf::RenderWindow &target, bool isButtonClicked) {
    static bool isTrapSelected = false, isTurretSelected = false;
    auto mousePos = sf::Mouse::getPosition(target);
    auto parentPos = bottomCoords(WIDTH / 1.2, 75);

    sf::RectangleShape background({WIDTH / 1.2, 75});
    background.setPosition(parentPos.first, parentPos.second);
    background.setFillColor(sf::Color::Blue);
    target.draw(background);

    sf::RectangleShape coinIcon({75, 75});
    coinIcon.setTexture(&coin);
    coinIcon.setPosition(background.getPosition());
    coinIcon.move({background.getSize().x - coinIcon.getSize().x, 0});
    target.draw(coinIcon);

    sf::Text coinsInfo(std::to_string(game.getCoinsAmount()), SVFont);
    coinsInfo.setCharacterSize(32);
    auto centeredText = centeredCoords(coinsInfo.getOutlineThickness(), 32, 10,
                                       background.getSize().y);

    coinsInfo.setPosition(coinIcon.getPosition().x, centeredText.second + parentPos.second);
    coinsInfo.move({-50, 0});
    coinsInfo.setFillColor(sf::Color(255, 201, 0));
    target.draw(coinsInfo);

    sf::RectangleShape turretIcon({background.getSize().y * 0.8f, background.getSize().y * 0.8f});
    turretIcon.setPosition(background.getPosition());
    turretIcon.setTexture(&towerBase);
    target.draw(turretIcon);
    turretIcon.setTexture(&towerWeapon);


    auto pos = turretIcon.getPosition();
    auto size = turretIcon.getSize();
    auto isOnTurret = isIntersecting(pos.x, pos.y, mousePos.x, mousePos.y, size.x, size.y);
    if ((isOnTurret && game.getCoinsAmount() >= Tower().getPrice()) || isTurretSelected) {
        turretIcon.setOutlineThickness(2);
        turretIcon.setOutlineColor(sf::Color::Green);
        if (isButtonClicked) {
            isTurretSelected = true;
        }
    } else if (isButtonClicked) {
        isTurretSelected = false;
    }
    target.draw(turretIcon);
    sf::Text turretPrice(std::to_string(Tower().getPrice()), SVFont, 20);
    turretPrice.setPosition(turretIcon.getPosition());
    turretPrice.move({20, turretIcon.getSize().y - 10});
    target.draw(turretPrice);

    sf::RectangleShape trapIcon({background.getSize().y * 0.8f, background.getSize().y * 0.8f});
    trapIcon.setPosition(turretIcon.getPosition());
    trapIcon.move({turretIcon.getSize().x + 20, 0});
    trapIcon.setTexture(&armedTrap);
    pos = trapIcon.getPosition();
    size = trapIcon.getSize();
    auto isOnTrap = isIntersecting(pos.x, pos.y, mousePos.x, mousePos.y, size.x, size.y);
    if ((isOnTrap && game.getCoinsAmount() >= Trap().getPrice()) ||
        isTrapSelected) {
        trapIcon.setOutlineThickness(2);
        trapIcon.setOutlineColor(sf::Color::Green);
        if (isButtonClicked) {
            isTrapSelected = true;
        }
    } else {
        isTrapSelected = false;
    }
    target.draw(trapIcon);
    sf::Text trapPrice(std::to_string(Trap().getPrice()), SVFont, 20);
    trapPrice.setPosition(trapIcon.getPosition());
    trapPrice.move({20, trapIcon.getSize().y - 10});
    target.draw(trapPrice);

    if (!isOnTurret && !isOnTrap && isButtonClicked && (isTurretSelected || isTrapSelected)) {
        // try to place thing
        auto tileCoords = getTileByCoords(mousePos.x, mousePos.y, game.getCurrentMap().getWidth(), game.getCurrentMap().getHeight());
        if (tileCoords.x >= 0 && tileCoords.x < game.getCurrentMap().getWidth() &&
            tileCoords.y >= 0 && tileCoords.y < game.getCurrentMap().getHeight()) {
            if (isTurretSelected) {
                game.addDefence(new Tower(tileCoords.x, tileCoords.y), false);
            } else if (isTrapSelected) {
                game.addDefence(new Trap(Slowness, tileCoords.x, tileCoords.y), false);
            }
        }
        isTurretSelected = false;
        isTrapSelected = false;
    }
}

void drawField(Game &game, sf::RenderWindow &target) {
    auto map = game.getCurrentMap();

    sf::RectangleShape shape({(float) map.getWidth() * TILE_SIZE, (float) map.getHeight() * TILE_SIZE});
    auto coords = centeredCoords(shape.getSize().x, shape.getSize().y);
    shape.setPosition(coords.first, coords.second);
    shape.setFillColor(sf::Color::White);
    target.draw(shape);
    for (int y = 0; y < map.getHeight(); y++) {
        for (int x = 0; x < map.getWidth(); x++) {
            sf::RectangleShape tileRect({TILE_SIZE, TILE_SIZE});
            tileRect.setPosition(coords.first + x * TILE_SIZE, coords.second + y * TILE_SIZE);
            auto tile = map.getTile(x, y);
            switch (tile->getType()) {
                case Road: {
                    tileRect.setTexture(&road);
                    break;
                }
                case Field: {
                    tileRect.setTexture(&field);
                    break;
                }
                case Forest: {
                    tileRect.setTexture(&forrest);
                    break;
                }
            }
            target.draw(tileRect);
            auto contents = tile->getContents();
            if (contents != nullptr) {
                if (contents->getType() == Base) {
                    sf::RectangleShape castleRect({TILE_SIZE, TILE_SIZE});
                    castleRect.setFillColor(sf::Color::Blue);
                    castleRect.setTexture(&castle);
                    castleRect.setPosition(coords.first + x * TILE_SIZE,
                                           coords.second + y * TILE_SIZE);
                    target.draw(castleRect);

                    sf::RectangleShape castleHpBox({TILE_SIZE, TILE_SIZE / 10}), castleHpInfo({TILE_SIZE *
                                                                                               ((float) dynamic_cast<Castle *>(contents)->getHP() /
                                                                                                (float) dynamic_cast<Castle *>(contents)->getMaxHp()),
                                                                                               TILE_SIZE / 10});
                    castleHpBox.setPosition(coords.first + x * TILE_SIZE,
                                            coords.second + y * TILE_SIZE);
                    castleHpInfo.setPosition(coords.first + x * TILE_SIZE,
                                             coords.second + y * TILE_SIZE);
                    castleHpBox.setFillColor(sf::Color::Black);
                    castleHpInfo.setFillColor(sf::Color::Green);
                    target.draw(castleHpBox);
                    target.draw(castleHpInfo);
//                } else if (typeid(contents) == typeid(Tower *)) {
                } else if (contents->getType() == Turret) {
                    sf::RectangleShape towerBaseRect({TILE_SIZE, TILE_SIZE}),
                            towerWeaponRect({TILE_SIZE, TILE_SIZE});
                    towerBaseRect.setTexture(&towerBase);
                    towerWeaponRect.setTexture(&towerWeapon);
                    towerBaseRect.setPosition(coords.first + x * TILE_SIZE,
                                              coords.second + y * TILE_SIZE);
                    towerWeaponRect.setPosition(coords.first + x * TILE_SIZE + towerWeaponRect.getSize().x / 2,
                                                coords.second + y * TILE_SIZE + towerWeaponRect.getSize().y / 2);
                    sf::Vector2f rectCenter(towerWeaponRect.getSize().x / 2, towerWeaponRect.getSize().y / 2);
                    towerWeaponRect.setOrigin(rectCenter);
                    towerWeaponRect.rotate((float) contents->getRotationDegree());
//                    contents->setRotation(contents->getRotationDegree() + 10);

                    target.draw(towerBaseRect);
                    target.draw(towerWeaponRect);

                } else if (contents->getType() == Spawn) {
                    sf::RectangleShape lairRect({TILE_SIZE, TILE_SIZE});
                    lairRect.setTexture(&lair);
                    lairRect.setPosition(coords.first + x * TILE_SIZE,
                                         coords.second + y * TILE_SIZE);
                    target.draw(lairRect);
                } else if (contents->getType() == ObjectType::Danger) {
                    sf::RectangleShape trapRect({TILE_SIZE, TILE_SIZE});
                    if (dynamic_cast<Trap *>(contents)->isActive()) {
                        trapRect.setTexture(&armedTrap);
                    } else {
                        trapRect.setTexture(&disarmedTrap);
                    }
                    trapRect.setPosition(coords.first + x * TILE_SIZE,
                                         coords.second + y * TILE_SIZE);
                    target.draw(trapRect);
                }
            }
        }
    }

    for (int i = 0; i < game.entities.size(); i++) {
        if (game.entities[i].isAlive()) {
            sf::RectangleShape entity({TILE_SIZE, TILE_SIZE});
            entity.setPosition(coords.first + game.entities[i].getPos().x * TILE_SIZE + TILE_SIZE / 2,
                               coords.second + game.entities[i].getPos().y * TILE_SIZE + TILE_SIZE / 2);
            sf::Vector2f rectCenter(entity.getSize().x / 2, entity.getSize().y / 2);
            entity.setOrigin(rectCenter);
            entity.rotate(game.entities[i].getRotationDegree());
//            game.entities[i].setRotation(game.entities[i].getRotationDegree() + 10);
//            game.entities[i].receiveDamage(1);

            entity.setTexture(&zombie);

            sf::RectangleShape hpBox({TILE_SIZE, TILE_SIZE / 10});
            hpBox.setPosition(coords.first + game.entities[i].getPos().x * TILE_SIZE,
                              coords.second + game.entities[i].getPos().y * TILE_SIZE);
            hpBox.setFillColor(sf::Color::Black);
            sf::RectangleShape hpInfo({TILE_SIZE *
                                       ((float) game.entities[i].getHPAmount() / (float) game.entities[i].getMaxHp()),
                                       TILE_SIZE / 10});
            hpInfo.setPosition(hpBox.getPosition());
            hpInfo.setFillColor(sf::Color::Green);
            target.draw(entity);
            target.draw(hpBox);
            target.draw(hpInfo);
        }
    }
}


int main() {
    loadTextures();
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Tower defence");
    window.setFramerateLimit(20);

//    SVFont.loadFromFile("game_files/fonts/Roboto/Roboto-Black.ttf");
    Game gameLogics;
    Matrix<sf::RectangleShape> tiles({{sf::RectangleShape({0, 0})}});
    Matrix<TileType> matrix(20, 8, Field);
    SVFont.loadFromFile("/Users/ssanyoq/MEOW/2023f/oopcpp/lab3/game_files/fonts/Stardew_Valley.ttf");

//    Matrix<TileType> matrix(map);
    matrix.addToBottom(1, Field);
    matrix.addToBottom(1, Forest);
    matrix.addToLeft(1, Forest);
    matrix.addToRight(1, Forest);
    matrix.addToTop(1, Forest);

    matrix.fillLine({.x=2, .y=2}, {.x=2, .y=7}, Road);
    matrix.fillLine({.x=2, .y=8}, {.x=13, .y=8}, Road);
    matrix.fillLine({.x=13, .y=8}, {.x=13, .y=3}, Road);
    matrix.fillLine({.x=13, .y=3}, {.x=9, .y=3}, Road);
    gameLogics.changeMap(Map(matrix, Coordinates{.x=9, .y=3}, {Coordinates{.x=2, .y=2}}));

    auto tower = Tower(4, 6, 1, ClosestToSelf);
    gameLogics.addDefence(&tower, true);
    gameLogics.addDefence(new Tower(6, 7, 1, ClosestToSelf), true);
    gameLogics.addDefence(new Trap(Slowness, 4, 8), true);

    dynamic_cast<Lair *>(gameLogics.getCurrentMap().getTile(2, 2)->getContents())->
            generateQueue(Entity(), 999, 40, 2);
    auto mousePos = sf::Mouse::getPosition(window);
    bool isButtonClicked;
    while (window.isOpen()) {
        sf::Event event{};
        sf::sleep(sf::milliseconds(20));
        isButtonClicked = false;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed: {
                    window.close();
                    break;
                }
                case sf::Event::MouseButtonPressed: {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        isButtonClicked = true;
                    }
                    break;
                }

            }
        }

        window.clear();
        drawField(gameLogics, window);
        drawGUI(gameLogics, window, isButtonClicked);
        if (gameLogics.isOver()) {
            sf::Text gameover("Game over", SVFont, 30);
            gameover.setPosition(WIDTH / 2, HEIGHT / 2);
            gameover.setFillColor(sf::Color::Red);
            window.draw(gameover);
        } else {
            gameLogics.process();
        }
        window.display();
    }

    return 0;
}
