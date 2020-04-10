#include "Game.h"


Game::Game() {
    level = Level();
    menu = Menu();
    state = 1;
    level.prepareLevel();
}

void Game::calculateFrame(){
    if (state == 0) { // if state == menu
        //state = menu.calculateFrame();

    } else if (state == 1) { // if state == level
        state = level.calculateFrame();
    }
}

void Game::drawFrame(sf::RenderWindow& window) {
    if (state == 0) { // if state == menu
        menu.draw(window);

    } else if (state == 1) { // if state == level
        level.draw(window);
    }
}