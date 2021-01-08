#pragma once

#include "../../Controllers/GameController.h"
#include "ButtonInterface.h"
class LoadGameButton : public ButtonInterface
{
public:
	LoadGameButton(float x, float y);
	void onClick();
	bool isClicked(sf::Vector2i point);
};

LoadGameButton::LoadGameButton(float x, float y) {
	//rec.setSize(sf::Vector2f(width, height));

	text.setFont(*Factory::getFont());
	text.setString("Load Game");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setPosition(sf::Vector2f(x, y));
}

void LoadGameButton::onClick()
{
	std::cout << "sadfsadf";
}

bool LoadGameButton::isClicked(sf::Vector2i point)
{
	return text.getGlobalBounds().contains(sf::Vector2f((float)point.x, (float)point.y));
}