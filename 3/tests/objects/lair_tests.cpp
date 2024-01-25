#include "../catch2/catch_amalgamated.hpp"
#include "../../objects/lair.h"

TEST_CASE("Lair Queue Operations") {
    Lair lair;

    SECTION("Add entities to the queue") {
        Entity entity1(1);
        Entity entity2(2);

        lair.addToQueue(entity1, 2);
        lair.addToQueue(entity2, 3);

        auto queue = lair.getQueue();
        REQUIRE(queue.size() == 2);
        REQUIRE(queue[0].first.getHPAmount() == 1);
        REQUIRE(queue[1].first.getHPAmount() == 2);
        REQUIRE(queue[0].second == 2);
        REQUIRE(queue[1].second == 5); // Delay accumulates

        SECTION("Reset the queue") {
            LairQueue newQueue = {{Entity(3), 1}, {Entity(4), 2} };
            lair.resetQueue(std::move(newQueue));

            auto newQueueResult = lair.getQueue();
            REQUIRE(newQueueResult.size() == 2);
            REQUIRE(newQueueResult[0].first.getHPAmount() == 3);
            REQUIRE(newQueueResult[1].first.getHPAmount() == 4);
            REQUIRE(newQueueResult[0].second == 1);
            REQUIRE(newQueueResult[1].second == 3); // Delay accumulates
        }
    }

    SECTION("Tick updates the queue") {
        Entity entity1(1);
        lair.addToQueue(entity1, 2);
        REQUIRE_NOTHROW(lair.tick());
    }
}

TEST_CASE("Lair Path Operations") {
    Lair lair;

    SECTION("Set path to castle") {
        Path path = {Coordinates{.x = 0, .y = 0},
                     Coordinates{.x = 1, .y = 0},
                     Coordinates{.x = 2, .y = 0},
                     Coordinates{.x = 2, .y = 1},
                     Coordinates{.x = 1, .y = 1},
                     Coordinates{.x = 1, .y = 0}};
        lair.setPath(path);

        REQUIRE(lair.getPath().size() == path.size());
        REQUIRE(lair.getPath()[3].x == 2);
        REQUIRE(lair.getPath()[5].y == 0);

    }
}