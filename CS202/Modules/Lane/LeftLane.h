#pragma once
#include "LaneInterface.h"

class LeftLane : public LaneInterface
{
public:
	LeftLane(int x);
	void initialize();
	void update();
	void playStreetSound(People& p);
};

LeftLane::LeftLane(int x) : LaneInterface(x) {
	texture.loadFromFile("Images//road.jpg");
	texture.setRepeated(true);
	rec.setPosition(sf::Vector2f(0.f, x));
	rec.setSize(sf::Vector2f(1280, 72.f));
	rec.setTexture(&texture);
	num_SoundVehicle = 0;
}
