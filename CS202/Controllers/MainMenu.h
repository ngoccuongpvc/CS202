#pragma once

#include "MenuInterface.h"
#include <iostream>
class MainMenu : public MenuInterface
{
public:
	MainMenu();
	void showMenu();
};

MainMenu::MainMenu()
{
	this->buttons.push_back(new NewGameButton(200, 50));
	this->buttons.push_back(new LoadGameButton(200, 50));
}

void MainMenu::showMenu()
{
	for (ButtonInterface* button : buttons)
	{
		button->draw();
	}
	
	sf::RenderWindow* window = Factory::getRenderWindow();
	window->display();

	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::TextEntered:
				std::cout << "keyboard pressed" << std::endl;
				break;
			case sf::Event::MouseButtonPressed:
				for (ButtonInterface* button : buttons) {
					if (button->isClicked(sf::Mouse::getPosition(*window))) {
						button->onClick();
					}
				}
				break;
			default:
				break;
			}
		}
	}
}