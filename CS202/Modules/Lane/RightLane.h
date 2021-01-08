#pragma once
#include "LaneInterface.h"

class RightLane : public LaneInterface
{
public:
	RightLane(int x);
	void initialize();
	void update();
	void playStreetSound(People& p);
};

RightLane::RightLane(int x) : LaneInterface(x) {
	texture.loadFromFile("Images//road.jpg");
	texture.setRepeated(true);
	rec.setPosition(sf::Vector2f(0.f, x));
	rec.setSize(sf::Vector2f(1280, 72.f));
	rec.setTexture(&texture);
	num_SoundVehicle = 0;
}

void RightLane::initialize()
{
	srand(time(NULL));
	float speed = static_cast<float>(rand()) / RAND_MAX;
	velocity = sf::Vector2f(-speed, 0);

	light.initialize(x, false);

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
			delete vehicles.back();
			vehicles.pop_back();
		}
	}

	light.updateLight();
}

void RightLane::playStreetSound(People& p) {
	sf::Sprite* pSprite = p.getSprite();

	for (auto& vehicle : vehicles) {
		float tmp = vehicle->getSprite()->getPosition().x - vehicle->getSprite()->getLocalBounds().width - (pSprite->getPosition().x + pSprite->getGlobalBounds().width);

		if (tmp < 1 && tmp > 0 && (pSprite->getGlobalBounds().intersects(this->rec.getGlobalBounds()))) {
				vehicle->getSound()->play();
				break;
			//std::cout << "Gap vat can roi ciu ciu ciu " << std::endl;
		}
	}
}