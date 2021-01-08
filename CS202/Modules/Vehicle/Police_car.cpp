#include "Police_car.h"

Police_car::Police_car()
{
    this->filename = "Images\\police_car.png";
    this->soundfile = "Audio\\car_sound.wav";

    texture = TextureLoader::loadTexture(filename);
    this->sprite = new sf::Sprite();
    this->sprite->setTexture(*texture);
}
