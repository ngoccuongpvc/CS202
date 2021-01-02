#pragma once
#include "LaneInterface.h"

class RightLane : public LaneInterface
{
public:
	RightLane(int x);
	void initialize();
	void update();
};

RightLane::RightLane(int x) : LaneInterface(x) {}

void RightLane::initialize()
{
	srand(time(NULL));
	float speed = static_cast<float>(rand()) / RAND_MAX;
	velocity = sf::Vector2f(-speed, 0);

	float lastPos = 0;
	VehicleInterface* vehicle;
	srand(static_cast<unsigned int> (time(nullptr)));
	while (lastPos < 1280) {
		vehicle = CarFactory::getRandom();
		vehicle->setVelocity(velocity);
		lastPos += (vehicles.empty() ? 0 : vehicles.back()->getSprite()->getGlobalBounds().width) + static_cast<float>(rand() % 500);
		vehicle->getSprite()->setPosition(sf::Vector2f(lastPos, x));
		vehicles.push_back(vehicle);
	}
}

void RightLane::update()
{
	if (!vehicles.empty()) {
		float firstPos = vehicles.front()->getSprite()->getPosition().x;
		if (firstPos < 1280) {
			vehicles.push_front(CarFactory::getRandom());

			float pos = firstPos + vehicles.front()->getSprite()->getGlobalBounds().width + static_cast<float>(rand() % 500);
			vehicles.front()->getSprite()->setPosition(pos, x);
			vehicles.front()->setVelocity(velocity);
		}
		if (vehicles.back()->getSprite()->getPosition().x + vehicles.back()->getSprite()->getGlobalBounds().width < 0) {
			vehicles.pop_back();
		}
	}
}