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
    CollisionAnimation();
    ~CollisionAnimation();
    void draw(float x, float y);
    void update();
    void restart();

    bool is_done;
};

CollisionAnimation::CollisionAnimation()
{
    restart();
    
    std::string filename = "Images//Frame0.png";
 
    for (int i = 0; i < vector_size; i++)
    {
        filename[filename.size() - 5] = '0' + i + 1;
        texture.push_back(new sf::Texture);
        texture[i]->loadFromFile(filename);

        frames.push_back(new sf::Sprite);
        frames[i]->setTexture(*texture[i]);
        //frames[i]->setPosition(player->getPosition());
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

void CollisionAnimation::draw(float x, float y)
{
    sf::RenderWindow *window = Factory::getRenderWindow();
    
    //window->draw(*frames[frame_cnt]);
    for (auto& frame : frames) {
        frame->setPosition(sf::Vector2f(x-frame->getGlobalBounds().width/2, y - frame->getGlobalBounds().height / 2));
        window->draw(*frame);
        window->display();
        sf::sleep(sf::microseconds(10000));
    }
    //update();
}