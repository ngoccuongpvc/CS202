#pragma once
#include <vector>
#include <deque>
#include "../Vehicle/CarFactory.h"
#include "../../Factory.h"
#include "TrafficLight.h"
#include "../People.h"

class LaneInterface
{
protected:
	std::deque<VehicleInterface*> vehicles;
	sf::RectangleShape rec;
	sf::Texture texture;
	sf::Vector2f velocity;
	int x;
	int num_SoundVehicle;
	bool have_light = 0;
	TrafficLight light;

public:
	LaneInterface(int x);
	virtual void initialize() = 0;
	virtual void draw();
	virtual void update() = 0;
	virtual void playStreetSound(People& p) = 0;
	virtual sf::RectangleShape getRec();
	bool checkCollision(People& p);
};
