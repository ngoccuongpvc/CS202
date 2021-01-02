#pragma once
#include <vector>
#include <deque>
#include "../Vehicle/CarFactory.h"
#include "../../Factory.h"

class LaneInterface
{
protected:
	std::deque<VehicleInterface*> vehicles;
	sf::RectangleShape rec;
	sf::Texture texture;
	sf::Vector2f velocity;
	int x;

public:
	LaneInterface(int x);
	virtual void initialize() = 0;
	virtual void draw();
	virtual void update() = 0;
};

LaneInterface::LaneInterface(int x) {
	this->x = x;
}

void LaneInterface::draw() {
	sf::RenderWindow *window = Factory::getRenderWindow();
	
	this->update();
	for (auto& vehicle : vehicles) {
		vehicle->move();
		window->draw(*vehicle->getSprite());
	}
}