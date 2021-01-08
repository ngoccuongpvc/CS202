#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>
class TextureLoader
{
public:
	static std::map<std::string, sf::Texture *> mapper;
	static sf::Texture *loadTexture(std::string path);
};

std::map<std::string, sf::Texture *> TextureLoader::mapper;