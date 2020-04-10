#include "Player.h"
#include <utility>


Player::Player(){
    frame_rotation = 0; // frame rotation_int for animation
    state = 0;
    is_player_right_orientation = true;
}



void Player::changeSprite(){
    int frame = 0;
    int moving = 0;

    if(state == 0) {
        if (frame_rotation >= 60) frame_rotation = 0; // jump from 3d to 1st frame
        moving = 0;
    }else{
        ++frame_rotation;
        if (frame_rotation >= 100) frame_rotation = 0; // jump from 5th to 1st frame
        moving = 1;
    }

    frame = frame_rotation / 20 * 48;


    sprite_player.setTextureRect(sf::IntRect(frame, 61 * moving, 45, 60 + 5 * moving));
    ++frame_rotation;
}


void Player::draw(sf::RenderWindow& window){ // draw procedure
    changeSprite();

    int tmp = (is_player_right_orientation ? 1 : -1);
    sprite_player.setScale(tmp, 1); // mirrored if looks to the right direction

    sprite_player.setPosition(sf::Vector2f(pos_x, pos_y));

    window.draw(sprite_player);


    //weapon.Draw(window, window_w, window_h, pos_x, pos_y, mouse_x, mouse_y);

}

void Player::calculateMove(Map& map) {
    int up = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    int down = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    int right = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    int left = sf::Keyboard::isKeyPressed(sf::Keyboard::A);

    int delta_x = (right - left) * speed; // fictitious X position
    int delta_y = (down - up) * speed; // fictitious Y position

    if (map.playerMoveX(delta_x)) {
        map_x = map.getPlayerPos().first;
        if (this->tryMoveX(delta_x)) {
            map.setMovementX(0);
        } else {
            map.setMovementX(-delta_x);
        }
    }
    if (map.playerMoveY(delta_y)) {
        map_y = map.getPlayerPos().second;
        if (this->tryMoveY(delta_y)) {
            map.setMovementY(0);
        } else {
            map.setMovementY(-delta_y);
        }
    }
    
    state = (right == left && down == up ? 0 : 1);

    if(right > left) is_player_right_orientation = true;
    if(right < left) is_player_right_orientation = false;
}


void Player::preparePlayer(std::pair<int, int> player_poses) {
    speed = 3;
    
    texture_player.loadFromFile("pictures/player.png");
    sprite_player.setTexture(texture_player);
    sprite_player.setOrigin(sf::Vector2f(22, 40));

    map_x = player_poses.first;
    map_y = player_poses.second;

    pos_x = map_x;
    pos_y = map_y;
}

bool Player::tryMoveX(int delta_x) {
    bool exit_code;
    if (1280 > pos_x + delta_x && pos_x + delta_x > 640) {
        pos_x += delta_x;
        exit_code = true;
    } else {
        exit_code = false;
    }
    return exit_code;
}

bool Player::tryMoveY(int delta_y) {
    bool exit_code;
    if (720 > pos_y + delta_y && pos_y + delta_y > 360) {
        pos_y += delta_y;
        exit_code = true;
    } else {
        exit_code = false;
    }
    return exit_code;
}
