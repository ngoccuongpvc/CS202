#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../Factory.h"
#include "People.h"

class CollisionAnimation
{
private:
    std::vector<sf::Sprite*> frames;
    const int vector_size = 9; //if size > 9 check ctor
    int frame_cnt;
    std::vector<sf::Texture*> texture;
public:
    CollisionAnimation(People &p);
    ~CollisionAnimation();
    void draw();
    void update();
    void restart();

    bool is_done;
};

CollisionAnimation::CollisionAnimation(People &p)
{
    restart();
    
    std::string filename = "Images//Frame0.png";
    sf::Sprite* player = p.getSprite();
    for (int i = 0; i < vector_size; i++)
    {
        filename[filename.size() - 5] = '0' + i + 1;
        texture.push_back(new sf::Texture);
        texture[i]->loadFromFile(filename);

        frames.push_back(new sf::Sprite);
        frames[i]->setTexture(*texture[i]);
        frames[i]->setPosition(player->getPosition());
    }
}

CollisionAnimation::~CollisionAnimation()
{
    for (int i = 0; i < vector_size; i++)
    {
        delete frames[i];
        delete texture[i];
    }
}

void CollisionAnimation::restart()
{
    is_done = false;
    frame_cnt = 0;
}

void CollisionAnimation::update()
{
    if (++frame_cnt >= vector_size)
    {
        is_done = true;
        frame_cnt = 0;
    }
}

void CollisionAnimation::draw()
{
    if (is_done) return;

    sf::RenderWindow *window = Factory::getRenderWindow();
    window->draw(*frames[frame_cnt]);
    update();
}