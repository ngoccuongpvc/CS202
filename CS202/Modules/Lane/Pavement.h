#pragma once
#include "LaneInterface.h"

class Pavement : public LaneInterface {
public:
	void initialize(int level);
	Pavement(int x);
	void update(int level);
	void playStreetSound(People& p);
};

Pavement::Pavement(int x) : LaneInterface(x) {
	texture.loadFromFile("Images//pavement.jpg");
	//texture.setRepeated(true);
	rec.setPosition(sf::Vector2f(0.f, x));
	rec.setSize(sf::Vector2f(1280, 72.f));
	rec.setTexture(&texture);
}

void Pavement::initialize(int level) {
	srand(time(NULL));
	float speed = 0;
	velocity = sf::Vector2f(speed, 0);
	float lastPos = 0;
	VehicleInterface* vehicle;
	srand(static_cast<unsigned int> (time(nullptr)));
	while (lastPos < 1280) {
		vehicle = new Tree();
		vehicle->setVelocity(velocity);
		lastPos += (vehicles.empty() ? 0 : vehicles.back()->getSprite()->getGlobalBounds().width) + static_cast<float>(rand() % 350);
		vehicle->getSprite()->setPosition(sf::Vector2f(lastPos, x));
		vehicles.push_back(vehicle);
	}
}
void Pavement::playStreetSound(People& p) {}
void Pavement::update(int level) {
}