#pragma once

class Dog : public VehicleInterface {
public:
	Dog();
};

Dog::Dog() {
	this->filename = "Images\\dog.png";
	this->soundfile = "Audio\\dog_sound.wav";

	texture->loadFromFile(filename);
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*texture);

	buffer->loadFromFile(soundfile);
	this->sound = new sf::Sound();
	this->sound->setBuffer(*buffer);
}
