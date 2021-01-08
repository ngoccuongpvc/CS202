#include "TrafficLight.h"
#include "../Factory.h"

TrafficLight::TrafficLight(): 
    is_red(false), red_time(0), total_time(0) 
{
	//texture.loadFromFile(filename);
	//sprite.setTexture(texture);    
}

void TrafficLight::initialize(int x_from_lane, bool is_left)
{
    srand(time(NULL));
    total_time = total_time_lower_limit + rand() % total_time_rand_limit;
    red_time = red_time_lower_limit + rand() % (total_time / 2);
    is_red = false;

    startClock();
    updateLight();
    //int width = sprite.getTexture()->getSize().x * sprite.getScale().x;
    int width = sprite.getGlobalBounds().width;
    sprite.setPosition((is_left)? (1280 - width) : (0 + width),  x_from_lane);
}

void TrafficLight::startClock()
{
    clk.restart();
}

void TrafficLight::updateLight()
{
    int cur_time = clk.getElapsedTime().asMilliseconds();
    if (cur_time > total_time) clk.restart();

    cur_time %= total_time;
    if (is_red) 
    {
        if (cur_time >= red_time)
        {
            is_red = false;
            //change image to green
            texture.loadFromFile(green_light_filename);
	        sprite.setTexture(texture);  
        }
    }
    else 
        if (cur_time < red_time)
        {
            is_red = true;
            //change image to red
            texture.loadFromFile(red_light_filename);
	        sprite.setTexture(texture);  
        }
}

void TrafficLight::draw()
{
    sf::RenderWindow *window = Factory::getRenderWindow();
    window->draw(sprite);
}