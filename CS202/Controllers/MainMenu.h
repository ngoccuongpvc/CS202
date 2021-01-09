#pragma once

#include "MenuInterface.h"
#include <iostream>
class MainMenu : public MenuInterface
{
private:
	sf::RectangleShape rect;
	sf::Text tittle;
public:
	MainMenu();
	void showMenu();
};

MainMenu::MainMenu()
{
	rect.setFillColor(sf::Color::Black);
	rect.setOutlineColor(sf::Color::Red);
	rect.setOutlineThickness(3);
	rect.setPosition(sf::Vector2f(495, 290));
	rect.setSize(sf::Vector2f(230, 150));

	tittle.setFont(*Factory::getFont());
	tittle.setString("CROSSING ROAD GAME");
	tittle.setCharacterSize(60);
	tittle.setFillColor(sf::Color::White);
	tittle.setPosition(sf::Vector2f(300, 150));

	this->buttons.push_back(new NewGameButton(520, 300));
	this->buttons.push_back(new LoadGameButton(545, 350));
	this->buttons.push_back(new ExitGameButton(580, 400));

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
		window->clear();
		window->draw(rect);
		window->draw(tittle);
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
