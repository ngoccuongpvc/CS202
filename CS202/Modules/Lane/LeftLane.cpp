#include "LeftLane.h"

void LeftLane::initialize()
{
	srand(time(NULL));
	float speed = static_cast<float>(rand()) / RAND_MAX;
	velocity = sf::Vector2f(speed, 0);

	light.initialize(x, true);

	float lastPos = 0;
	VehicleInterface* vehicle;
	srand(static_cast<unsigned int> (time(nullptr)));
	while (lastPos < 1280) {
		vehicle = CarFactory::getRandom();
		vehicle->getSprite()->setScale(-1.f, 1.f);
		vehicle->setVelocity(velocity);
		lastPos += (vehicles.empty() ? 0 : vehicles.back()->getSprite()->getGlobalBounds().width) + static_cast<float>(rand() % 500);
		vehicle->getSprite()->setPosition(sf::Vector2f(lastPos, x));
		vehicles.push_back(vehicle);
	}
}

void LeftLane::update()
{
	if (!vehicles.empty()) {
		float firstPos = vehicles.front()->getSprite()->getPosition().x;
		if (firstPos > 0) {
			vehicles.push_front(CarFactory::getRandom());
			vehicles.front()->getSprite()->setScale(-1.f, 1.f);
			float pos = firstPos - vehicles.front()->getSprite()->getGlobalBounds().width - static_cast<float>(rand() % 500);
			vehicles.front()->getSprite()->setPosition(pos, x);
			vehicles.front()->setVelocity(velocity);
		}
		if (vehicles.back()->getSprite()->getPosition().x > 1280) {
			delete vehicles.back();
			vehicles.pop_back();
		}
	}

	light.updateLight();
}

void LeftLane::playStreetSound(People& p) {
	sf::Sprite* pSprite = p.getSprite();

	for (auto& vehicle : vehicles) {
		float tmp = pSprite->getPosition().x - (vehicle->getSprite()->getPosition().x + vehicle->getSprite()->getGlobalBounds().width);
		if (tmp < 1 && tmp > 0 && (pSprite->getGlobalBounds().intersects(this->rec.getGlobalBounds()))) {
				vehicle->getSound()->play();
				break;
			//std::cout << "Gap vat can roi ciu ciu ciu " << std::endl;
		}
	}
}