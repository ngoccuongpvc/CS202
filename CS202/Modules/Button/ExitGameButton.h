#pragma once

#include "ButtonInterface.h"
class ExitGameButton : public ButtonInterface
{
public:
	ExitGameButton(float x, float y);
	void onClick();
	bool isClicked(sf::Vector2i point);
};

ExitGameButton::ExitGameButton(float x, float y) {

	text.setFont(*Factory::getFont());
	text.setString("Exit");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(x, y));
}

void ExitGameButton::onClick()
{
	std::cout << "Exitting..." << std::endl;
	exit(0);
}

bool ExitGameButton::isClicked(sf::Vector2i point)
{
	return text.getGlobalBounds().contains(sf::Vector2f((float)point.x, (float)point.y));
}