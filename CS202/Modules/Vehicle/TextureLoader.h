#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>
class TextureLoader
{
public:
	static std::map<std::string, sf::Texture*> mapper;
	static sf::Texture* loadTexture(std::string path) {
		if (TextureLoader::mapper[path] == nullptr) {
			TextureLoader::mapper[path] = new sf::Texture();
			TextureLoader::mapper[path]->loadFromFile(path);
		}
		return TextureLoader::mapper[path];
	}
};

std::map<std::string, sf::Texture*> TextureLoader::mapper;