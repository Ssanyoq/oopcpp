#include "../catch2/catch_amalgamated.hpp"
#include "castle.h"

TEST_CASE("Castle Initialization and Basic Functionality") {
    SECTION("Default Constructor") {
        Castle castle(100, 0, 0);
        REQUIRE(castle.getHP() == 100);
        REQUIRE_FALSE(castle.isDead());
    }

    SECTION("Custom Constructor") {
        Castle castle(150, 2, 3);
        REQUIRE(castle.getHP() == 150);
        REQUIRE_FALSE(castle.isDead());
        // Add more checks for other parameters
    }
}

TEST_CASE("Castle Damage and Health") {
    SECTION("Receive Damage") {
        Castle castle(100, 0, 0);
        castle.receiveDamage(30);
        REQUIRE(castle.getHP() == 70);
        castle.receiveDamage(80);
        REQUIRE(castle.getHP() == 0);
        REQUIRE(castle.isDead());
    }

    SECTION("Receive Zero Damage") {
        Castle castle(100, 0, 0);
        castle.receiveDamage(0);
        REQUIRE(castle.getHP() == 100);
        REQUIRE_FALSE(castle.isDead());
    }
}
