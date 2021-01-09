#pragma once
#include <vector>
#include <deque>
#include "../Vehicle/CarFactory.h"
#include "../../Factory.h"
#include "TrafficLight.h"
#include "../People.h"
#include "../../Utility/RandomMachine.h"

class LaneInterface
{
protected:
	std::deque<VehicleInterface*> vehicles;
	sf::RectangleShape rec;
	sf::Texture texture;
	sf::Vector2f velocity;
	int x;
	
	bool have_light = 0;
	TrafficLight light;

public:
	LaneInterface(int x);
	virtual void initialize(int level) = 0;
	virtual void draw();
	virtual void update(int *level) = 0;
	virtual void playStreetSound(People& p) = 0;
	void resetVehicles();
	bool checkCollision(People& p);
};

LaneInterface::LaneInterface(int x) {
	this->x = x;
}

void LaneInterface::draw() {
	sf::RenderWindow *window = Factory::getRenderWindow();
	
	//this->update();
	window->draw(rec);
	for (auto& vehicle : vehicles) {
		if (!light.isRed())
			vehicle->move();
		window->draw(*vehicle->getSprite());
	}
	light.draw();
}

void LaneInterface::resetVehicles()
{
	vehicles.clear();
}

bool LaneInterface::checkCollision(People& p)
{
	sf::Sprite* player = p.getSprite();
	sf::RectangleShape entity;
	entity.setPosition(player->getPosition());
	entity.move(sf::Vector2f(5,20));
	entity.setSize(sf::Vector2f(10, 10));
	if (!rec.getGlobalBounds().intersects(entity.getGlobalBounds()))
		return false;
	
	for (auto& vehicle : vehicles)
		if (entity.getGlobalBounds().intersects(vehicle->getSprite()->getGlobalBounds()))
		{
			//std::cout << player->getGlobalBounds().left << " " << player->getGlobalBounds().top << " " << player->getGlobalBounds().width << " " << player->getGlobalBounds().height << std::endl;
			//std::cout << vehicle->getSprite()->getGlobalBounds().left << " " << vehicle->getSprite()->getGlobalBounds().top << " " << vehicle->getSprite()->getGlobalBounds().width << " " << vehicle->getSprite()->getGlobalBounds().height << std::endl;
			return true;
		}
	return false;
}

