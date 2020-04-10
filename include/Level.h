#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H


#include "Player.h"
#include "Mob.h"
#include "Map.h"

class Level {
private:
    int state; // 0 - current level; 1 - pause
    Player player;
    std::vector<Mob> mobs;
    Map map;

public:
    explicit Level();
    void prepareLevel();
    int calculateFrame();
    void draw(sf::RenderWindow& window);
};


#endif //GAME_LEVEL_H
