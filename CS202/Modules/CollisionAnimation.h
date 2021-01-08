#ifndef _CollisionAnimation_H_
#define _CollisionAnimation_H_


#include <vector>
#include <SFML/Graphics.hpp>
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

#endif