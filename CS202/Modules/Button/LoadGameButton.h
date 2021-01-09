#pragma once

#include "../../Controllers/GameController.h"
#include "ButtonInterface.h"
#include <fstream>
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
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(x, y));
}

void LoadGameButton::onClick()
{
	int level;
	std::ifstream fin;
	fin.open("SaveGame.txt");
	fin>>level;
	fin.close();

	GameController processor(level);
	processor.start();
}

bool LoadGameButton::isClicked(sf::Vector2i point)
{
	return text.getGlobalBounds().contains(sf::Vector2f((float)point.x, (float)point.y));
}