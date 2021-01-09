#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "../Modules/People.h"
#include "../Modules/Lane/LaneInterface.h"
#include "../Modules/Lane/LeftLane.h"
#include "../Modules/Lane/RightLane.h"
#include "../Modules/Lane/Pavement.h"
#include  "../Modules/CollisionAnimation.h"
#include "PauseMenu.h"
#include <string>
#include <SFML/System.hpp>
#include <functional>
class GameController
{
private:
	People player;
	CollisionAnimation colision;
	std::vector<LaneInterface*> lanes;
	std::vector<sf::Thread*> vThreads;
	sf::RectangleShape rect;
	sf::Text text;
	int level = 0;
public:
	GameController(int level);
	void start();
};

GameController::GameController(int level)
{
	rect.setFillColor(sf::Color::Black);
	rect.setOutlineColor(sf::Color::Red);
	rect.setOutlineThickness(3);
	rect.setPosition(sf::Vector2f(10, 15));
	rect.setSize(sf::Vector2f(65, 30));

	text.setFont(*Factory::getFont());
	text.setCharacterSize(15);
	text.setFillColor(sf::Color::Red);
	text.setPosition(sf::Vector2f(15, 20));

	this->level = level;
	lanes.push_back(new Pavement(0));
	for (int i = 1; i < 9; i += 2) {
		lanes.push_back(new LeftLane(i * 72));
		lanes.push_back(new RightLane((i + 1) * 72));
	}
	lanes.push_back(new Pavement(9 * 72));
	for (auto& lane : lanes) {
		vThreads.push_back(new sf::Thread(std::bind(&LaneInterface::update, lane, &this->level)));

	}
}

void GameController::start() {
	sf::RenderWindow* window = Factory::getRenderWindow();

	PauseMenu pauseMenu(level);
	text.setString("Level: " + std::to_string(level + 1));
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
					if (pauseMenu.showMenu())
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

		//for (auto& thread : vThreads) {
		//	thread->launch();
		//}
		//for (auto& thread : vThreads) {
		//	thread->wait();
		//}
		for (auto& lane : lanes) {
			lane->update(&level);
			lane->draw();
		}
		window->draw(rect);
		window->draw(text);
		for (int i = 1; i < 9; ++i) {
			lanes[i]->playStreetSound(player);
			if (lanes[i]->checkCollision(player)) {
				colision.draw(player.getSprite()->getPosition().x, player.getSprite()->getPosition().y);
				return;
			}
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
