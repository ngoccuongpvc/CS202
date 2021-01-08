#pragma once

#include "ButtonInterface.h"
class ContinueGameButton : public ButtonInterface
{
public:
	ContinueGameButton(float width, float height);
	void onClickPause(bool& check);
	bool isClicked(sf::Vector2i point);
};

ContinueGameButton::ContinueGameButton(float x, float y) {
	text.setFont(*Factory::getFont());
	text.setString("Continue");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(x, y));
}

void ContinueGameButton::onClickPause(bool& check)
{
	check = false;
}

bool ContinueGameButton::isClicked(sf::Vector2i point)
{
	return text.getGlobalBounds().contains(sf::Vector2f((float)point.x, (float)point.y));
}