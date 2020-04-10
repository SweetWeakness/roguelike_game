#ifndef GAME_WEAPON_H
#define GAME_WEAPON_H


#include <SFML/Graphics.hpp>


class Weapon {
private:
    sf::Texture texture_weapon;
    sf::Sprite sprite_weapon;

    double alpha_weapon;

public:
    explicit Weapon();
    void draw(sf::RenderWindow& window, int window_w, int window_h, int pos_x, int pos_y, int mouse_x, int mouse_y);
    void draw(sf::RenderWindow& window, int window_w, int window_h, int pos_x, int pos_y);
};


#endif //GAME_WEAPON_H
