#pragma once

#include "ButtonInterface.h"
#include <fstream>
#include <string>

class SaveGameButton : public ButtonInterface
{
private:
	int level;
public:
	SaveGameButton(float width, float height, int level);
	void onClickPause(bool& check);
	bool isClicked(sf::Vector2i point);
};

SaveGameButton::SaveGameButton(float x, float y, int level) 
{
	std::string str = "Save Game (lv " + std::to_string(level + 1) + ")";
	this->level = level;
	text.setFont(*Factory::getFont());
	text.setString(str);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(x, y));
}

void SaveGameButton::onClickPause(bool& check)
{
	std::cout << "Save Game " << level << std::endl;
	std::ofstream fout;
	fout.open("SaveGame.txt");
	fout << level;
	fout.close();
	check = true;
}

bool SaveGameButton::isClicked(sf::Vector2i point)
{
	return text.getGlobalBounds().contains(sf::Vector2f((float)point.x, (float)point.y));
}