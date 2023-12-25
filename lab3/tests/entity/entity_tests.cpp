#include "../catch2/catch_amalgamated.hpp"
#include "entity.h"

TEST_CASE("Entity Initialization and Basic Functionality") {
    SECTION("Default Constructor") {
        Entity entity(100);
        REQUIRE(entity.isAlive());
        REQUIRE(entity.getHPAmount() == 100);
    }

    SECTION("Custom Constructor") {
        Entity entity(150, 2, 50, 3, 20);
        REQUIRE(entity.isAlive());
        REQUIRE(entity.getHPAmount() == 150);
        // Add more checks for other parameters
    }

    SECTION("Receive Damage") {
        Entity entity(100, 2, 50, 3, 20);
        entity.receiveDamage(30);
        REQUIRE(entity.getHPAmount() == 70);
        entity.receiveDamage(80);
        REQUIRE(!entity.isAlive());
        REQUIRE(entity.getHPAmount() == 0);
    }
}

TEST_CASE("Entity Movement and Path") {
    SECTION("Spawn and Move") {
        Entity entity;
        Path path = { {0, 0}, {1, 1}, {2, 2} };
        entity.spawn(path);
        REQUIRE(entity.isAlive());
        REQUIRE(entity.getPos().x == path[0].x);

        Castle castle(100, 0, 0);
        entity.move(castle);
        // Add more checks for movement and path handling
    }
}

TEST_CASE("Entity Effects") {
    SECTION("Use Effects") {
        Entity entity;
        Effect effect1(Poison);
        Effect effect2(Fatigue);

        entity.getEffect(effect1);
        entity.getEffect(effect2);

        entity.useEffects();
        // Add checks for the effects on entity attributes after calling useEffects()
    }

    SECTION("Receive Damage with Effects") {
        Entity entity(100, 2, 50, 3, 20);
        Effect damageEffect(Poison);

        entity.getEffect(damageEffect);
        entity.useEffects();

        REQUIRE(entity.getHPAmount() < 100);

        // Add checks for the entity's HP after applying damage effects
    }
}