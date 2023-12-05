#include "../catch2/catch_amalgamated.hpp"
#include "../../utility/functions.h"
#include "tile_type.h"

//#include <iostream>
//using std::cout;

TEST_CASE("Path finding") {
    vector<vector<TileType>> map = {{Road,  Road, Road},
                                    {Road,  Road, Road},
                                    {Field, Road, Road}};

//    Map m(map, Coordinates{.x = 0, .y = 0},{Coordinates{.x = 2, .y = 0}});
//    m.printMap();

    auto out = getDistances(map, Coordinates{.x=0, .y=0});
    REQUIRE(out[0][0] == 0);
    REQUIRE(out[0][1] == 1);
    REQUIRE(out[1][0] == 1);
    REQUIRE(out[1][1] == 2);
    REQUIRE(out[2][2] == 4);
    /*
     012
     123
     #34
     */

//    for (int i = 0; i < out.size(); i++) { // Prints
//        for (int j = 0; j < out[i].size(); j++) {
//            if (out[i][j] == -1) {
//                cout << '#';
//            } else {
//                cout << out[i][j];
//            }
//        }
//        cout << std::endl;
//    }

    auto out2 = getPath(out, Coordinates{.x = 1, .y = 2});
    REQUIRE(out2.size() == 3);
//    for (int i = 0; i < out2.size(); i++) {
//        cout << out2[i].x << "," << out2[i].y << std::endl;
//    }

}