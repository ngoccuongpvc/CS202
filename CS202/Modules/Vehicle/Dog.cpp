#include "Dog.h"
Dog::Dog()
{
    this->filename = "Images\\dog.png";
    this->soundfile = "Audio\\dog_sound.wav";

    texture = TextureLoader::loadTexture(filename);
    this->sprite = new sf::Sprite();
    this->sprite->setTexture(*texture);
}