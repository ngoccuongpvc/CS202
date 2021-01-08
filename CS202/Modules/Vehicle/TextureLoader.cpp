#include "TextureLoader.h"
static sf::Texture *TextureLoader::loadTexture(std::string path)
{
    if (TextureLoader::mapper[path] == nullptr)
    {
        TextureLoader::mapper[path] = new sf::Texture();
        TextureLoader::mapper[path]->loadFromFile(path);
    }
    return TextureLoader::mapper[path];
}