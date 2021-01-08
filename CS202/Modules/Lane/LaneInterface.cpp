#include "LaneInterface.h"

sf::RectangleShape LaneInterface::getRec() {
	return this->rec;
}
LaneInterface::LaneInterface(int x) {
	this->x = x;
}

void LaneInterface::draw() {
	sf::RenderWindow* window = Factory::getRenderWindow();

	window->draw(rec);
	for (auto& vehicle : vehicles) {
		vehicle->move();
		window->draw(*vehicle->getSprite());
	}
	light.draw();
}

void LaneInterface::resetVehicles()
{
	vehicles.clear();
}

bool LaneInterface::checkCollision(People& p)
{
	sf::Sprite* player = p.getSprite();
	if (!rec.getGlobalBounds().intersects(player->getGlobalBounds()))
		return false;
	for (auto& vehicle : vehicles)
		if (player->getGlobalBounds().intersects(
			vehicle->getSprite()->getGlobalBounds()
		))
		{
			return true;
		}
	return false;
}