#include "Truck.h"

Truck::Truck()
{
    this->filename = "Images\\truck.png";
    this->soundfile = "Audio\\truck_sound.wav";

    texture = TextureLoader::loadTexture(filename);
    this->sprite = new sf::Sprite();
    this->sprite->setTexture(*texture);
}