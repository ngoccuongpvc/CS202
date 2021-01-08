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

	texture->loadFromFile(filename);
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*texture);

	
	buffer->loadFromFile(soundfile);
	this->sound = new sf::Sound();
	this->sound->setBuffer(*buffer);
}