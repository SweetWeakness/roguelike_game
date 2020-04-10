#include "Weapon.h"
#include <cmath>
#define PI 3.14159265


double getAlphaOfAim(int posx, int posy, int aim_x, int aim_y){
    double tmp = aim_x - posx;
    if(tmp > 0) return (90 - atan( (posy - aim_y) / tmp ) * 180 / PI);
    if(tmp < 0) return (atan( (aim_y - posy) / tmp ) * 180 / PI - 90);
    return (aim_y > posy ? 180 : 0);
}


Weapon::Weapon(){
    texture_weapon.loadFromFile("../pictures/gun.png");
    texture_weapon.setSmooth(true);
    sprite_weapon.setTexture(texture_weapon);
    sprite_weapon.setOrigin(6, 45);

    alpha_weapon = 90;
}

void Weapon::draw(sf::RenderWindow& window, int window_w, int window_h, int pos_x, int pos_y, int mouse_x, int mouse_y){

    alpha_weapon = getAlphaOfAim(pos_x, pos_y, mouse_x, mouse_y);

    if(alpha_weapon > 0){
        sprite_weapon.setScale(1, 1); // its needed bcs of "else" setting scale (get default pic)
    }else{
        sprite_weapon.setScale(-1, 1); // mirrored if looks to the right direction
    }

    sprite_weapon.setPosition(sf::Vector2f(pos_x, pos_y));
    sprite_weapon.setRotation(alpha_weapon);
    window.draw(sprite_weapon);
}

void Weapon::draw(sf::RenderWindow& window, int window_w, int window_h, int pos_x, int pos_y){
    sprite_weapon.setPosition(sf::Vector2f(pos_x, pos_y));
    window.draw(sprite_weapon);
}