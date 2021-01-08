#include "Tree.h"
Tree::Tree()
{
    this->filename = "Images\\tree.png";
    texture = TextureLoader::loadTexture(filename);
    this->sprite = new sf::Sprite();
    this->sprite->setTexture(*texture);
}