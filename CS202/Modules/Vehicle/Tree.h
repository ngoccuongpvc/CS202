#pragma once

#include "VehicleInterface.h"

class Tree : public VehicleInterface {
public:
	Tree();
};

Tree::Tree() {
	this->filename = "Images\\tree.png";
	texture->loadFromFile(filename);
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*texture);
}