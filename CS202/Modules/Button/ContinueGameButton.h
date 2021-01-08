#pragma once

#include "ButtonInterface.h"
class ContinueGameButton : public ButtonInterface
{
public:
	ContinueGameButton(float width, float height);
	void onClick();
	bool isClicked(sf::Vector2i point);
};

ContinueGameButton::ContinueGameButton(float width, float height) {
	rec.setSize(sf::Vector2f(width, height));

	text.setFont(*Factory::getFont());
	text.setString("Continue");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
}

void ContinueGameButton::onClick()
{
	
}

bool ContinueGameButton::isClicked(sf::Vector2i point)
{
	return rec.getGlobalBounds().contains(sf::Vector2f((float)point.x, (float)point.y));
}