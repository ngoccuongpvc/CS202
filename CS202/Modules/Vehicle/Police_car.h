#pragma once
class Police_car : public VehicleInterface {
public:
	Police_car();
};

Police_car::Police_car() {
	this->filename = "Images\\police_car.png";
	this->soundfile = "Audio\\car_sound.wav";

	texture->loadFromFile(filename);
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*texture);

	buffer->loadFromFile(soundfile);
	this->sound = new sf::Sound();
	this->sound->setBuffer(*buffer);
}
