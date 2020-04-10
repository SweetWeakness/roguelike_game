#ifndef GAME_MAP_H
#define GAME_MAP_H


#include <utility>
#include <tuple>
#include <map>
#include <SFML/Graphics.hpp>


class Map {
    int player_x, player_y;
    int move_x, move_y;
    int absolute_x, absolute_y;
    sf::Texture floor_texture;
    sf::Sprite floor_sprite;
    std::multimap<int, std::pair<int, sf::Sprite&>> to_draw;
public:
    Map();
    void prepareMap();
    std::pair<int, int> getPlayerPos();
    bool playerMoveX(int delta_x);
    bool playerMoveY(int delta_y);
    void setMovementY(int delta);
    void setMovementX(int delta);
    void calculateMove();
    void draw(sf::RenderWindow& window);
};


#endif //GAME_MAP_H
