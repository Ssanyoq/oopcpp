#include "../catch2/catch_amalgamated.hpp"
#include "tower.h"
#include "../../utility/functions.h"


TEST_CASE("Tower Shoot Functionality") {
    SECTION("Shoot at Closest Entity") {
        Tower tower(0, 0, 50, ClosestToSelf, 10);  // Mock tower with range and damage
        std::vector<Entity> entities{
                Entity(1, 1),  // Closest to (0,0)
                Entity(3, 3),
                Entity(2, 2),
        };

        tower.shoot(entities);

        // Check if tower rotated towards the closest entity
        REQUIRE(tower.getRotationDegree() == (short)calculateAngle(tower.getPos(), entities[0].getPos()));

        // Check if closest entity received damage
        REQUIRE(entities[0].getHPAmount() == 0);  // Add a suitable method to Entity class
    }

    // Add more test cases to cover different scenarios, e.g., entities outside range, different attack strategies, etc.
}