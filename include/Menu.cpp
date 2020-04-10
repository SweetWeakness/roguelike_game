#include <iostream>
#include "Menu.h"



/*

    void rightButtonPressed(int mouse_x, int mouse_y, int window_w, int window_h){
        if(mouse_x > window_w / 10 && mouse_x < window_w / 10 + 256){
            int tmp = window_h * 2 / 10;

            if(mouse_y > tmp && mouse_y < tmp + 72) state = "start pressed";
            if(mouse_y > 2 * tmp && mouse_y < 2 * tmp + 72) state = "settings pressed";
            if(mouse_y > 3 * tmp && mouse_y < 3 * tmp + 72) state = "exit pressed";
        }
    }

    void rightButtonReleased(int mouse_x, int mouse_y, int window_w, int window_h){
        if(mouse_x > window_w / 10 && mouse_x < window_w / 10 + 256){
            int tmp = window_h * 2 / 10;

            if(mouse_y > tmp && mouse_y < tmp + 72 && state == "start pressed") state = "in start menu";
            if(mouse_y > 2 * tmp && mouse_y < 2 * tmp + 72 && state == "settings pressed") state = "in settings menu";
            if(mouse_y > 3 * tmp && mouse_y < 3 * tmp + 72 && state == "exit pressed") state = "exiting";

        }else{
            state = "default";
        }

        std::cout << state <<"\n";
    }

    */
Menu::Menu() {
    texture_background.loadFromFile("../pictures/background.png");
    sprite_background.setTexture(texture_background);
    sprite_background.setPosition(sf::Vector2f(0, 0));

    button_texture.create(256, 72);//loadFromFile("../pictures/start.png");
    button_sprite.setTexture(button_texture);

    state = "default";
}

void Menu::draw(sf::RenderWindow& window) {
    int window_w = 1920;
    int window_h = 1080;
    if(state == "default"){
        window.draw(sprite_background);

        button_texture.loadFromFile("../pictures/start.png");
        button_sprite.setPosition(sf::Vector2f(window_w / 10, window_h * 2 / 10));
        window.draw(button_sprite);

        button_texture.loadFromFile("../pictures/settings.png");
        button_sprite.setPosition(sf::Vector2f(window_w / 10, window_h * 4 / 10));
        window.draw(button_sprite);

        button_texture.loadFromFile("../pictures/exit.png");
        button_sprite.setPosition(sf::Vector2f(window_w / 10, window_h * 6 / 10));
        window.draw(button_sprite);
        std::cout << "xui";
    }

    if(state == "start pressed"){
        window.draw(sprite_background);

        button_texture.loadFromFile("../pictures/start_pressed.png");
        button_sprite.setPosition(sf::Vector2f(window_w / 10, window_h * 2 / 10));
        window.draw(button_sprite);

        button_texture.loadFromFile("../pictures/settings.png");
        button_sprite.setPosition(sf::Vector2f(window_w / 10, window_h * 4 / 10));
        window.draw(button_sprite);

        button_texture.loadFromFile("../pictures/exit.png");
        button_sprite.setPosition(sf::Vector2f(window_w / 10, window_h * 6 / 10));
        window.draw(button_sprite);
    }

    if(state == "settings pressed"){
        window.draw(sprite_background);

        button_texture.loadFromFile("../pictures/start.png");
        button_sprite.setPosition(sf::Vector2f(window_w / 10, window_h * 2 / 10));
        window.draw(button_sprite);

        button_texture.loadFromFile("../pictures/settings_pressed.png");
        button_sprite.setPosition(sf::Vector2f(window_w / 10, window_h * 4 / 10));
        window.draw(button_sprite);

        button_texture.loadFromFile("../pictures/exit.png");
        button_sprite.setPosition(sf::Vector2f(window_w / 10, window_h * 6 / 10));
        window.draw(button_sprite);
    }

    if(state == "exit pressed"){
        window.draw(sprite_background);

        button_texture.loadFromFile("../pictures/start.png");
        button_sprite.setPosition(sf::Vector2f(window_w / 10, window_h * 2 / 10));
        window.draw(button_sprite);

        button_texture.loadFromFile("../pictures/settings.png");
        button_sprite.setPosition(sf::Vector2f(window_w / 10, window_h * 4 / 10));
        window.draw(button_sprite);

        button_texture.loadFromFile("../pictures/exit_pressed.png");
        button_sprite.setPosition(sf::Vector2f(window_w / 10, window_h * 6 / 10));
        window.draw(button_sprite);
    }

}

void Menu::calculateFrame() {
    true;
}
