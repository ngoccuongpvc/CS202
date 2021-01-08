#pragma once

#include "../../Controllers/GameController.h"
#include "ButtonInterface.h"
class NewGameButton : public ButtonInterface
{
public:
	NewGameButton(float x, float y);
	void onClick();
	bool isClicked(sf::Vector2i point);
};

NewGameButton::NewGameButton(float x, float y) {
	//rec.setSize(sf::Vector2f(width, height));

	text.setFont(*Factory::getFont());
	text.setString("Start New Game");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setPosition(sf::Vector2f(x, y));
}

void NewGameButton::onClick()
{
	GameController processor(0);
	processor.start();
}

bool NewGameButton::isClicked(sf::Vector2i point)
{
	return text.getGlobalBounds().contains(sf::Vector2f((float)point.x, (float)point.y));
}