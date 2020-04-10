#include <iostream>
#include "Level.h"


Level::Level(){
    state = 0;
    player = Player();
    map = Map();
}


int Level::calculateFrame() {
    player.calculateMove(map);
    map.calculateMove();
    for (int i = 0; i < mobs.size(); ++i) {
        mobs[i].calculateMove();
    }
    return 1;
}


void Level::draw(sf::RenderWindow& window){
    if(state == 0){
        map.draw(window);
        player.draw(window);
    }
}


void Level::prepareLevel() {
    map.prepareMap();
    player.preparePlayer(map.getPlayerPos());
    for (int i = 0; i < mobs.size(); ++i) {
        mobs[i].prepareMob();
    }
}



/*
 * sf::IntRect Level::getRect(int link){
    return sf::IntRect(--link * 48,  0, 48, 48);
}

 *         for(int i = 0; i < 38; i++){
            for(int j = 0; j < 20; j++){
                sprite_field.setTextureRect(getRect(ground[i][j]));
                sprite_field.setPosition(sf::Vector2f(48 + i * 48, 60 + j * 48));
                window.draw(sprite_field);
            }
        }
        sprite
        sprite_field.setTextureRect(sf::IntRect(48,  0, 48, 48)));
        sprite_field.setPosition(sf::Vector2f(48 + move_x, 60 + move_y));
 */