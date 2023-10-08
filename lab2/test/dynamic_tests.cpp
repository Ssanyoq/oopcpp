#include "../catch2/catch_amalgamated.hpp"
#include "../dynamic/dynamic_octets.h"

#define SET_RAND srand(time(NULL))
#define RAND_RANGE 1000

TEST_CASE("Empty constructor") {
    DynamicOctets dO;

    REQUIRE(dO.getLength() == 0);
    REQUIRE_THROWS_AS(dO[1], std::invalid_argument);
    SUCCEED();
}

TEST_CASE("Non-empty constructor") {
    SET_RAND;
    size_t len = (rand()) % RAND_RANGE + 1; // for time effectiveness
    DynamicOctets o(len);
    REQUIRE(o.getLength() == len);
    for (int i = 0; i < len; i++) {
        REQUIRE_NOTHROW(o[i][0]);
    }
    SUCCEED();
}

TEST_CASE("Resize") {
    SECTION("New size > older one") {
        DynamicOctets o(10);
        o.resize(100);
        REQUIRE(o.getLength() == 100);
        for (int i = 0; i < 100; i++) {
            REQUIRE_NOTHROW(o[i][0]);
        }
    }SECTION("New size < older one") {
        DynamicOctets o(100);
        o.resize(10);
        REQUIRE(o.getLength() == 10);
        for (int i = 0; i < 10; i++) {
            REQUIRE_NOTHROW(o[i][0]);
        }
    }SECTION("Same size"){
        size_t len = rand() % RAND_RANGE + 1;
        DynamicOctets o(len);
        o.resize(len);
        REQUIRE(o.getLength() == len);
        for (int i = 0; i < len; i++) {
            REQUIRE_NOTHROW(o[i][0]);
        }
    }
}

TEST_CASE("[]") {
    SET_RAND;
    SECTION("i >= size") {
        int size = rand() % RAND_RANGE;
        unsigned ind = rand() + size + 1;
        DynamicOctets o(size);
        REQUIRE_THROWS_AS(o[ind], std::invalid_argument);
    }SECTION("i < 0") {
        int size = rand() % RAND_RANGE;
        unsigned ind = -rand() - 1;
        DynamicOctets o(size);
        REQUIRE_THROWS_AS(o[ind], std::invalid_argument);
    }
}