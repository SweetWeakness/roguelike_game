cmake_minimum_required(VERSION 3.14)
project(game)

#set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2.5.1 COMPONENTS graphics)
add_executable(game main.cpp include/Menu.cpp include/Menu.h include/Game.cpp include/Game.h include/Level.cpp include/Level.h include/Player.cpp include/Player.h include/Weapon.cpp include/Weapon.h include/Bounds.cpp include/Bounds.h include/test.cpp include/test.h include/Mob.cpp include/Mob.h include/Map.cpp include/Map.h)

target_link_libraries(game sfml-graphics)

