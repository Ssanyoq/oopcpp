cmake_minimum_required(VERSION 3.26)
project(lab3)

set(CMAKE_CXX_STANDARD 14)

include_directories(effects)
include_directories(entities)
include_directories(game_features)
include_directories(objects)

add_executable(lab3
        effects/effect.h
        entities/entity.h
        game_features/game.h
        game_features/map.h
        objects/castle.cpp
        objects/castle.h
        objects/defence.h
        objects/lair.h
        objects/placeable.h
        objects/sprite.h
        objects/tile.h
        objects/tower.h
        objects/trap.h
        objects/sprite.cpp
        main.cpp
        config.h
        game_features/game.cpp
        game_features/map.cpp
        game_features/map.cpp
        game_features/map.cpp
        utility/functions.cpp
        utility/functions.h
        utility/functions.h
        utility/coords.h
        effects/effect.cpp
        utility/warning.h
)
