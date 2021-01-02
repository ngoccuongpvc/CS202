#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "../Modules/People.h"
#include "../Modules/Lane/LaneInterface.h"
#include "../Modules/Lane/LeftLane.h"
#include "../Modules/Lane/RightLane.h"


class GameController
{
private:
	People player;
	std::vector<LaneInterface*> lanes;

public:
	GameController();
	void start();
};

GameController::GameController()
{
	for (int i = 0; i < 10; i+=2) {
		lanes.push_back(new LeftLane(i*72));
		lanes.back()->initialize();
		
		lanes.push_back(new RightLane((i+1)*72));
		lanes.back()->initialize();
	}
}

void GameController::start() {
	sf::RenderWindow* window = Factory::getRenderWindow();

	window->clear();

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
		player.draw();

		for (auto& lane : lanes) {
			lane->draw();
		}
		sf::sleep(sf::microseconds(1000));
		window->display();
	}
	
}