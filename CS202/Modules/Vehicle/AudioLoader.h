#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <map>
class AudioLoader
{
public:
	static std::map<std::string, sf::SoundBuffer *> mapper;
	static sf::SoundBuffer *loadBuffer(std::string path);
	static std::map<std::string, sf::Sound *> sound;
	static sf::Sound *loadSound(std::string path);
};

std::map<std::string, sf::SoundBuffer *> AudioLoader::mapper;
std::map<std::string, sf::Sound *> AudioLoader::sound;