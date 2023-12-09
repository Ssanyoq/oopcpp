#include "../catch2/catch_amalgamated.hpp"
#include "tile_type.h"
#include "map.h"
using std::vector;


TEST_CASE("Map initialization and tests") {
    vector<vector<TileType>> mapTypes = {{Road,  Road, Road},
                                        {Road,  Road, Road},
                                        {Field, Road, Road}};
    REQUIRE(true);
    Map map(mapTypes, Coordinates{.x = 0, .y = 0}, {Coordinates{.x = 2, .y = 0},
                                                    Coordinates {.x = 0, .y = 1}});

    map.printMap();

    REQUIRE(dynamic_cast<Lair *>(map.getTile(0, 1)->getContents()) != nullptr);
    REQUIRE_NOTHROW(dynamic_cast<Lair *>(map.getTile(2, 0)->getContents())->doAction());

    REQUIRE(map.isAccurate());

    REQUIRE(map.getWidth() == 3);
    REQUIRE(map.getHeight() == 3);

    auto castleCoords = map.getCastleCoords();
    REQUIRE(castleCoords.x == 0);
    REQUIRE(castleCoords.y == 0);
}
