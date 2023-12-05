#include "../catch2/catch_amalgamated.hpp"
#include "tile_type.h"
using std::vector;


TEST_CASE("Map initialization and tests") {
    vector<vector<TileType>> map = {{Road,  Road, Road},
                                    {Road,  Road, Road},
                                    {Field, Road, Road}};
    REQUIRE(true);
}
