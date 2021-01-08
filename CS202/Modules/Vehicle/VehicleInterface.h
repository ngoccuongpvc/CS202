#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TextureLoader.h"
#include "AudioLoader.h"

class VehicleInterface
{
protected:
	std::string filename = "";
	std::string soundfile = "";
	sf::Texture *texture;
	sf::Sprite *sprite;
	sf::Vector2f velocity;

public:
	VehicleInterface();
	virtual sf::Sprite *getSprite();
	void move();
	virtual sf::Sound *getSound();
	void setVelocity(sf::Vector2f velocity);
};