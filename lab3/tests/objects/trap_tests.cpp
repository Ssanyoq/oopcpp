#include "../catch2/catch_amalgamated.hpp"
#include "trap.h"

TEST_CASE("Trap Functionality") {
    SECTION("Deal Effect to Closest Entity") {
        Trap trap(EffectType::Poison, 0, 0, 0, 10);  // Mock trap with cooldown and effect
        std::vector<Entity> entities{
                Entity(1, 1),  // Closest to (0,0)
                Entity(3, 3),
                Entity(2, 2),
        };

        trap.dealEffect(entities);
        entities[0].useEffects();

        // Check if closest entity received the effect
        REQUIRE(!entities[0].isAlive());  // Add a suitable method to Entity class
        // Check if cooldown is set after dealing the effect
//        REQUIRE(trap.getCooldown() == trap.getCooldownDuration());
    }

    SECTION("Do Action (Trigger Effect)") {
        Trap trap(EffectType::Slowness, 0, 0, 0, 10);  // Mock trap with cooldown and effect
        std::vector<Entity> entities{
                Entity(1, 1),  // Closest to (0,0)
                Entity(3, 3),
                Entity(2, 2),
        };

        trap.dealEffect(entities);

        trap.doAction(entities);

        // Check if cooldown is decreased after doing the action

        // Check if another effect is applied to the closest entity
    }

    // Add more test cases to cover different scenarios, e.g., cooldown duration, different effect types, etc.
}
