//
// Created by Daniil on 10.04.2020.
//

#include "test.h"

void test::met(sf::RenderWindow& window) {
    sf::Sprite sprite;
    sf::Texture texture;
    texture.loadFromFile("D:\\JetBrains Projects\\CLion Projects\\Game\\pictures\\player.png");
    sprite.setTexture(texture);
    sprite.setOrigin(sf::Vector2f(22, 40));
    window.draw(sprite);
}
