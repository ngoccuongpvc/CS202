#pragma once

#include "ButtonInterface.h"
#include <fstream>

class SaveGameButton : public ButtonInterface
{
private:
	int level;
public:
	SaveGameButton(float width, float height, int level);
	void onClick();
	bool isClicked(sf::Vector2i point);
};

SaveGameButton::SaveGameButton(float width, float height, int level) 
{
	this->level = level;
	rec.setSize(sf::Vector2f(width, height));

	text.setFont(*Factory::getFont());
	text.setString("Save Game");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
}

void SaveGameButton::onClick()
{
	std::cout << "Save Game" << std::endl;
	std::ofstream fout;
	fout.open("SaveGame.txt");
	fout << level;
	fout.close();
}

bool SaveGameButton::isClicked(sf::Vector2i point)
{
	return rec.getGlobalBounds().contains(sf::Vector2f((float)point.x, (float)point.y));
}