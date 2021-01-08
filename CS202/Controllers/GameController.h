#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "../Modules/People.h"
#include "../Modules/Lane/LaneInterface.h"
#include "../Modules/Lane/LeftLane.h"
#include "../Modules/Lane/RightLane.h"
#include "../Modules/Lane/Pavement.h"

class GameController
{
private:
	People player;
	std::vector<LaneInterface*> lanes;
	int level = 0;
public:
	GameController(int level);
	void start();
};

GameController::GameController(int level)
{
	this->level = level;
	lanes.push_back(new Pavement(0));
	for (int i = 1; i < 9; i += 2) {
		lanes.push_back(new LeftLane(i * 72));
		lanes.push_back(new RightLane((i + 1) * 72));
	}
	lanes.push_back(new Pavement(9 * 72));
}

void GameController::start() {
	sf::RenderWindow* window = Factory::getRenderWindow();

	//PauseMenu pauseMenu;
	window->clear();

	for (int i = 0; i < lanes.size(); i++)
	{
		lanes[i]->resetVehicles();
		lanes[i]->initialize(level);
	}
	player.startPosition();

	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::KeyPressed:
				switch (event.text.unicode)
				{
				case sf::Keyboard::A:
					player.moveLeft();
					break;
				case sf::Keyboard::S:
					player.moveDown();
					break;
				case sf::Keyboard::W:
					player.moveUp();
					break;
				case sf::Keyboard::D:
					player.moveRight();
					break;
				case sf::Keyboard::Escape:
					//pauseMenu.showMenu();
					return;
					break;
				default:
					break;
				}
				break;
			case sf::Event::KeyReleased:
				switch (event.text.unicode)
				{
				case sf::Keyboard::A:
					player.moveRight();
					break;
				case sf::Keyboard::S:
					player.moveUp();
					break;
				case sf::Keyboard::W:
					player.moveDown();
					break;
				case sf::Keyboard::D:
					player.moveLeft();
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}
		window->clear();
		player.move();

		for (auto& lane : lanes) {
			lane->update(level);
			lane->playStreetSound(player);
			lane->draw();
		}
		player.draw();
		sf::sleep(sf::microseconds(1000));
		window->display();
		if (player.getSprite()->getPosition().y == 0)
		{
			level++;
			start(); //nextlevel
			return;
		}
	}
}
