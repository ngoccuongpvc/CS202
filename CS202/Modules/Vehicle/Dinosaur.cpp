#include "Dinosaur.h"
Dinosaur::Dinosaur()

{
    this->filename = "Images\\dinosaur.png";
    this->soundfile = "Audio\\dinosaur_sound.wav";

    texture = TextureLoader::loadTexture(filename);
    this->sprite = new sf::Sprite();
    this->sprite->setTexture(*texture);
}