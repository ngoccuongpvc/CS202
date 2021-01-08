#include "VehicleInterface.h"
VehicleInterface::VehicleInterface()
{
    this->texture = new sf::Texture();
    this->sprite = new sf::Sprite();
    velocity = sf::Vector2f(1.f, 0.f);
}
sf::Sprite *VehicleInterface::getSprite()
{
    return this->sprite;
}

sf::Sound *VehicleInterface::getSound()
{
    //return this->sound;
    return AudioLoader::loadSound(soundfile);
}

void VehicleInterface::move()
{
    this->sprite->move(velocity);
}

void VehicleInterface::setVelocity(sf::Vector2f velocity)
{
    this->velocity = velocity;
}
