#include <SFML/Graphics.hpp>
#include <iostream>

#include <random>
#include "include/Game.h"
#include "include/test.h"


int main()
{
    srand( time( 0 ) );
    // create the window
    int window_w = 1920;
    int window_h = 1080;
    sf::RenderWindow window(sf::VideoMode(window_w, window_h), "Game"); // , sf::Style::Fullscreen
    window.setFramerateLimit(120);

    //Menu menu = Menu();
    Game game = Game();



    int mouse_x = 0;
    int mouse_y = 0;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // check the type of the event...
            switch (event.type)
            {
                    // window closed
                case sf::Event::Closed:
                    window.close();
                    break;

                    // window resized
                case sf::Event::Resized:
                    window_w = event.size.width;
                    window_h = event.size.height;
                    std::cout << "new width: " << window_w << std::endl;
                    std::cout << "new height: " << window_h << std::endl;
                    break;

                    // mouse button pressed
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        mouse_x = event.mouseButton.x;
                        mouse_y = event.mouseButton.y;
                        std::cout << "the left button was pressed" << std::endl;
                        std::cout << "mouse x: " << mouse_x << std::endl;
                        std::cout << "mouse y: " << mouse_y << std::endl;
                        //menu.rightButtonPressed(mouse_x, mouse_y, window_w, window_h);
                    }
                    break;

                case sf::Event::MouseButtonReleased:
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        mouse_x = event.mouseButton.x;
                        mouse_y = event.mouseButton.y;
                        std::cout << "the left button was released" << std::endl;
                        std::cout << "mouse x: " << mouse_x << std::endl;
                        std::cout << "mouse y: " << mouse_y << std::endl;
                        //menu.rightButtonReleased(mouse_x, mouse_y, window_w, window_h);
                    }
                    break;

                case sf::Event::MouseMoved:
                    mouse_x = event.mouseMove.x;
                    mouse_y = event.mouseMove.y;
                    //std::cout << "new mouse x: " << mouse_x << std::endl;
                    //std::cout << "new mouse y: " << mouse_y << std::endl;
                    break;

                default:
                    break;
            }
        }

        // clear the window
        window.clear(sf::Color::White);
        game.calculateFrame();
        game.drawFrame(window);

        //.Draw(window, window_w, window_h, mouse_x, mouse_y);

        // end the current frame
        window.display();
    }


    return 0;
}