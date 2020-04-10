#include <iostream>
#include "Map.h"


Map::Map() {
    move_x = 0;
    move_y = 0;
    absolute_x = 0;
    absolute_y = 0;
    player_x = 960;
    player_y = 540;
}

void Map::prepareMap() {
    move_x = 0;
    move_y = 0;
    player_x = 960;
    player_y = 540;

    floor_texture.loadFromFile("pictures/ground.bmp");
    floor_sprite.setTexture(floor_texture);
    for (int i = 0;i<100;++i){
        int a,b;
        a = 48 * (i%10);
        b = 48 * (i/10);
        to_draw.emplace(a, std::pair<int, sf::Sprite&> {b, floor_sprite});
    }
    floor_sprite.setTextureRect(sf::IntRect(0,  0, 48, 48));
}

std::pair<int, int> Map::getPlayerPos() {
    return std::pair<int, int> {player_x, player_y};
}

bool Map::playerMoveX(int delta_x) {
    player_x += delta_x;
    return true;
}

bool Map::playerMoveY(int delta_y) {
    player_y += delta_y;
    return true;
}

void Map::setMovementY(int map_speed) {
    move_y = map_speed;
}

void Map::setMovementX(int map_speed) {
    move_x = map_speed;
}

void Map::draw(sf::RenderWindow& window) {
    for(auto iter = to_draw.begin(); iter!=to_draw.end(); ++iter){
        int sp_x = (*iter).first;
        int sp_y = (*iter).second.first;

        if (sp_x + absolute_x < 1920 && sp_x + absolute_x > -40 &&
                sp_y + absolute_y < 1080 && sp_y + absolute_y > -40) {

            sf::Sprite &sp_link = (*iter).second.second;
            sp_link.setPosition(absolute_x + sp_x, absolute_y + sp_y);
            window.draw(sp_link);
        }
    }
}

void Map::calculateMove() {
    absolute_x += move_x;
    absolute_y += move_y;
}


