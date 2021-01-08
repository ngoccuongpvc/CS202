#pragma once

#include "VehicleInterface.h"
class Car2 : public VehicleInterface {
public:
	Car2();
};

Car2::Car2() {
	this->filename = "Images\\car2.png";
	this->soundfile = "Audio\\car_sound.wav";

	texture = TextureLoader::loadTexture(filename);
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*texture);
}
