#include "AudioLoader.h"

static sf::SoundBuffer *AudioLoader::loadBuffer(std::string path)
{
    if (AudioLoader::mapper[path] == nullptr)
    {
        AudioLoader::mapper[path] = new sf::SoundBuffer();
        AudioLoader::mapper[path]->loadFromFile(path);
    }
    return AudioLoader::mapper[path];
}

static std::map<std::string, sf::Sound *> sound;
static sf::Sound *AudioLoader::loadSound(std::string path)
{
    if (AudioLoader::sound[path] == nullptr)
    {
        AudioLoader::sound[path] = new sf::Sound();
        AudioLoader::sound[path]->setBuffer(*AudioLoader::loadBuffer(path));
    }
    return AudioLoader::sound[path];
}