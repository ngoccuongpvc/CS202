#pragma once

#include "VehicleInterface.h"

class Dinosaur : public VehicleInterface {
public:
	Dinosaur();
};

Dinosaur::Dinosaur() {
	this->filename = "Images\\dinosaur.png";
	this->soundfile = "Audio\\dinosaur_sound.wav";

	texture->loadFromFile(filename);
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*texture);

	buffer->loadFromFile(soundfile);
	this->sound = new sf::Sound();
	this->sound->setBuffer(*buffer);
}
