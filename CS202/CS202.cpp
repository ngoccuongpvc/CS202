#include <iostream>
#include <vector>
#include <string>
#include <sfml\Graphics.hpp>
#include "Controllers/MainMenu.h"

#include "Modules/Vehicle/CarFactory.h"

int main()
{
    sf::RenderWindow *window = Factory::getRenderWindow();

    MainMenu menu;
    window->setKeyRepeatEnabled(false);
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();
        menu.showMenu();
        window->display();
    }

    return 0;
}
