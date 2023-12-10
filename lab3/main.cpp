
#include "utility/functions.h"
#include "tile_type.h"
#include "map.h"
#include <iostream>

using std::cout;

int main() {
    vector<vector<TileType>> map = {{Road,  Road, Road},
                                    {Field,  Field, Road},
                                    {Road, Field, Road}};

    Map m(map, Coordinates{.x = 0, .y = 0},{Coordinates{.x = 2, .y = 0}});
    m.printMap();
//    cout << typeid(m).name() << std::endl;

//    auto out = getDistances(map, Coordinates{.x=0, .y=0});
//    for (int i = 0; i < out.size(); i++) {
//        for (int j = 0; j < out[i].size(); j++) {
//            if (out[i][j] == -1) {
//                cout << '#';
//            } else {
//                cout << out[i][j];
//            }
//        }
//        cout << std::endl;
//    }
//    cout << std::endl;
//    auto out2 = getPath(out, Coordinates{.x = 2, .y = 2});
//    for (int i = 0; i < out2.size(); i++) {
//        cout << out2[i].x << "," << out2[i].y << std::endl;
//    }
//    Map map1(map, Coordinates{.x = 0, .y = 0}, {Coordinates{.x = 2, .y = 2}});
//    map1.printMap();
}