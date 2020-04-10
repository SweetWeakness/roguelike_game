#ifndef GAME_GAME_H
#define GAME_GAME_H


#include <iostream>
#include "Menu.h"
#include "Level.h"


class Game {
private:
    int state; // 0 - menu; 1 - level
    Level level;
    Menu menu;

public:
    explicit Game();
    void calculateFrame();
    void drawFrame(sf::RenderWindow& window);
};


#endif //GAME_GAME_H
