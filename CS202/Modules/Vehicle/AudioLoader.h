#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <map>
class AudioLoader
{
public:
	static std::map<std::string, sf::SoundBuffer*> mapper;
	static sf::SoundBuffer* loadBuffer(std::string path) {
		if (AudioLoader::mapper[path] == nullptr) {
			AudioLoader::mapper[path] = new sf::SoundBuffer();
			AudioLoader::mapper[path]->loadFromFile(path);
		}
		return AudioLoader::mapper[path];
	}

	static std::map<std::string, sf::Sound*> sound;
	static sf::Sound* loadSound(std::string path) {
		if (AudioLoader::sound[path] == nullptr) {
			AudioLoader::sound[path] = new sf::Sound();
			AudioLoader::sound[path]->setBuffer(*AudioLoader::loadBuffer(path));
		}
		return AudioLoader::sound[path];
	}
};

std::map<std::string, sf::SoundBuffer*> AudioLoader::mapper;
std::map<std::string, sf::Sound*> AudioLoader::sound;