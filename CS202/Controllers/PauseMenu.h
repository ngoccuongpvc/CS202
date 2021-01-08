#pragma once

#include "MenuInterface.h"

class PauseMenu : public MenuInterface
{
private:
	int level;
public:
	PauseMenu(int level);
	void showMenu();
};

PauseMenu::PauseMenu(int level)
{
	this->level = level;
	this->buttons.push_back(new SaveGameButton(200, 50, level));
	//this->buttons.push_back(new ContinueGameButton(200, 50));
}

void PauseMenu::showMenu()
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