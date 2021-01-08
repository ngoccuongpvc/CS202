#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class VehicleInterface
{
protected:
	std::string filename = "";
	std::string soundfile = "";
	sf::Texture* texture;
	sf::Sprite* sprite;
	sf::Vector2f velocity;
	sf::SoundBuffer* buffer;
	sf::Sound* sound;
public:
	VehicleInterface();
	virtual sf::Sprite* getSprite();
	void move();
	virtual sf::Sound* getSound();
	void setVelocity(sf::Vector2f velocity);
};

VehicleInterface::VehicleInterface()
{
	this->texture = new sf::Texture();
	this->sprite = new sf::Sprite();
	this->buffer = new sf::SoundBuffer();
	this->sound = new sf::Sound();
	velocity = sf::Vector2f(1.f, 0.f);
}
sf::Sprite* VehicleInterface::getSprite()
{
	return this->sprite;
}

sf::Sound* VehicleInterface::getSound() {
	return this->sound;
}

void VehicleInterface::move()
{
	this->sprite->move(velocity);
}

void VehicleInterface::setVelocity(sf::Vector2f velocity)
{
	this->velocity = velocity;
}