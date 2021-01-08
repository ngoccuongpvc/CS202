#pragma once

#include "VehicleInterface.h"

class Car : public VehicleInterface
{

public:
	Car();
};

Car::Car()
{
	this->filename = "Images\\car.png";
	this->soundfile = "Audio\\car_sound.wav";

	texture = TextureLoader::loadTexture(filename);
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*texture);
}