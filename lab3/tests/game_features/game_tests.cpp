#include "../catch2/catch_amalgamated.hpp"
#include "../../game_features/game.h"
#include "../../objects/tower.h"
#include "../../objects/trap.h"


TEST_CASE("Game testing") {
    Game game;
    vector<vector<TileType>> mapTypes = {{Road,  Road, Road},
                                         {Road,  Road, Road},
                                         {Field, Road, Road}};
    REQUIRE(true);
    Map map(Matrix<TileType>(mapTypes),
            Coordinates{.x = 0, .y = 0}, {Coordinates{.x = 1, .y = 0},
                                                    Coordinates {.x = 0, .y = 1}});

    game.changeMap(map);

    for (int i = 0; i < game.getCurrentMap().getHeight(); i++) {
        for (int j = 0; j < game.getCurrentMap().getWidth(); j++) {
            REQUIRE(game.getCurrentMap().getTile(j, i)->getType() == mapTypes[i][j]);
        }
    }
    auto entity = Entity(100);
    game.addEntity(entity);

    auto defence = new Tower(0, 0, 10);
    game.addDefence(defence, true);
    auto trap = new Trap(Poison);
    game.addDefence(trap, true);
    game.process();
}
