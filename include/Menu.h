#ifndef GAME_MENU_H
#define GAME_MENU_H


#include <SFML/Graphics.hpp>


class Menu {
private:
    sf::Texture texture_background;
    sf::Sprite sprite_background;
    sf::Texture button_texture;
    sf::Sprite button_sprite;
    std::string state;

public:
    explicit Menu();
    void calculateFrame();
    void draw(sf::RenderWindow& window);
};


#endif //GAME_MENU_H
