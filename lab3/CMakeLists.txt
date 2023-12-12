cmake_minimum_required(VERSION 3.26)
project(lab3)

set(CMAKE_CXX_STANDARD 14)


include_directories(effects)
include_directories(entities)
include_directories(game_features)
include_directories(objects)


file(GLOB game_features_src "game_features/*")
file(GLOB effects_src "effects/*")
file(GLOB objects_src "objects/*")
file(GLOB entities_src "entities/*")
file(GLOB util_src "utility/*")

add_library(game_features
        game_features/game.cpp
        game_features/game.h
        game_features/map.cpp
        game_features/map.h)

add_library(effects
        effects/effect.cpp
        effects/effect.h)


add_library(objects
        objects/castle.cpp
        objects/castle.h
        objects/defence.h
        objects/lair.cpp
        objects/lair.h
        objects/placeable.h
        objects/sprite.h
        objects/tile.h
        objects/tower.cpp
        objects/tower.h
        objects/tower_strategies.h
        objects/trap.cpp
        objects/trap.h
        objects/sprite.cpp
)

add_library(entities
        entities/entity.h
        entities/entity.cpp)

target_link_libraries(entities objects)
target_link_libraries(entities effects)
target_link_libraries(game_features objects)

add_library(utility
        utility/coords.h
        utility/functions.cpp
        utility/functions.h
        matrix/matrix.h
        utility/path.h
        utility/warning.h
        utility/closest_enemy.h
        utility/closest_enemy.cpp
        utility/warning.cpp
        utility/entity_enum.h
        matrix/matrix_iterator.h
)


add_executable(lab3
        #        effects/effect.h
        #        entities/entity.h
        #        game_features/game.h
        #        game_features/map.h
        #        objects/castle.cpp
        #        objects/castle.h
        #        objects/defence.h
        #        objects/lair.h
        #        objects/placeable.h
        #        objects/sprite.h
        #        objects/tile.h
        #        objects/tower.h
        #        objects/trap.h
        main.cpp
        config.h
)

# Specify the include directories
#target_include_directories(lab3 PRIVATE /opt/homebrew/Cellar/sfml/2.6.1/include)

# Specify the library directories
#link_directories(/opt/homebrew/Cellar/sfml/2.6.1/lib)

find_package(SFML 2.6.1 COMPONENTS graphics audio  REQUIRED)

target_link_libraries(lab3
        game_features
        effects
        objects
        entities
        utility
        sfml-graphics
        sfml-window
        sfml-system
)

# SFML

# g++ main.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include
# -o prog -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system



# Specify the libraries to link against using keyword syntax
#target_link_libraries(lab3 PRIVATE )

add_library(catch2
        tests/catch2/catch_amalgamated.hpp
        tests/catch2/catch_amalgamated.cpp

)

add_executable(test
        tests/utility/functions_tests.cpp
        tests/game_features/map_tests.cpp
        tests/game_features/game_tests.cpp
        tests/objects/lair_tests.cpp
        tests/entity/entity_tests.cpp
        tests/objects/castle_tests.cpp
        tests/objects/tower_tests.cpp
        tests/objects/trap_tests.cpp
)

target_link_libraries(test
        catch2
        game_features
        effects
        objects
        entities
        utility
)