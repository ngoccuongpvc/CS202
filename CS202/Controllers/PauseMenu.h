#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "../Modules/Button/ButtonInterface.h"
#include "../Modules/Button/SaveGameButton.h"
#include "../Modules/Button/ContinueGameButton.h"

class PauseMenu 
{
private:
	sf::RectangleShape rect;
	std::vector<ButtonInterface*> buttons;
	int level;
public:
	PauseMenu(int level);
	bool showMenu();
};

PauseMenu::PauseMenu(int level)
{
	rect.setFillColor(sf::Color::Black);
	rect.setOutlineColor(sf::Color::Red);
	rect.setOutlineThickness(3);
	rect.setPosition(sf::Vector2f(495, 290));
	rect.setSize(sf::Vector2f(230, 150));
	this->level = level;
	this->buttons.push_back(new SaveGameButton(520, 320, level));
	this->buttons.push_back(new ContinueGameButton(530, 370));
}

bool PauseMenu::showMenu()
{
	bool check = false;
	for (ButtonInterface* button : buttons)
	{
		button->draw();
	}

	sf::RenderWindow* window = Factory::getRenderWindow();
	window->display();

	while (window->isOpen()) {
		sf::Event event;
		window->draw(rect);
		for (ButtonInterface* button : buttons)
		{
			button->draw();
		}
		window->display();
		while (window->pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::MouseMoved:
				for (ButtonInterface* button : buttons) {
					button->changeColor(button->isClicked(sf::Mouse::getPosition(*window)));
				}
				break;
			case sf::Event::MouseButtonPressed:
				for (ButtonInterface* button : buttons) {
					if (button->isClicked(sf::Mouse::getPosition(*window))) {
						button->onClickPause(check);
						return check;
					}
				}
				break;
			default:
				break;
			}
		}
	}
}




