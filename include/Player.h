#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include <SFML/Graphics.hpp>
#include "Weapon.h"
#include "Map.h"


class Player {
private:
    int map_x, map_y; // absolute P position on map
    int pos_x, pos_y, speed;
    int state; // 0 - standing; 1 - moving
    sf::Texture texture_player;
    sf::Sprite sprite_player;
    Weapon weapon;
    int frame_rotation;
    bool is_player_right_orientation; // bool to check, if player looks at the right direction

public:
    explicit Player();
    void preparePlayer(std::pair<int, int> player_poses);
    void calculateMove(Map& map);
    void changeSprite();
    void draw(sf::RenderWindow& window);
    bool tryMoveX(int delta_x);
    bool tryMoveY(int delta_y);
};


#endif //GAME_PLAYER_H
