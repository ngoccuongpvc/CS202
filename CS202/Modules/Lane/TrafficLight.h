#include <vector>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include "../../Utility/RandomMachine.h"

class TrafficLight
{
private:
    bool is_red;
    int red_time, total_time, start_time; //in millisecond
    sf::Clock clk;
    const int total_time_rand_limit = 10000,
              total_time_lower_limit = 5000, 
              red_time_lower_limit = 1000;

    std::string red_light_filename = "Images//light_red.png",
                green_light_filename = "Images//light_green.png";
    sf::Sprite sprite;
    sf::Texture texture;

public:
    TrafficLight();
    void initialize(int x_from_lane, bool is_left);
    void startClock();
    void updateLight();
    void draw();
    bool isRed();
    static sf::Texture* redLight;
    static sf::Texture* greenLight;
};

sf::Texture* TrafficLight::redLight = nullptr;
sf::Texture* TrafficLight::greenLight = nullptr;

TrafficLight::TrafficLight(): 
    is_red(false), red_time(0), total_time(0) 
{
	//texture.loadFromFile(filename);
	//sprite.setTexture(texture);    
}

void TrafficLight::initialize(int x_from_lane, bool is_left)
{
    total_time = total_time_lower_limit + random() % total_time_rand_limit;
    red_time = red_time_lower_limit + random() % (total_time / 2);
    start_time = red_time -500 + random() % (total_time - red_time);
    is_red = false;

    startClock();
    updateLight();
    //int width = sprite.getTexture()->getSize().x * sprite.getScale().x;
    int width = sprite.getGlobalBounds().width;
    sprite.setPosition((is_left)? (1280 - width) : (0),  x_from_lane);
}

void TrafficLight::startClock()
{
    clk.restart();
}

void TrafficLight::updateLight()
{
    int cur_time = clk.getElapsedTime().asMilliseconds();
    if (cur_time > total_time) clk.restart(); 
    
    cur_time += start_time;
    cur_time %= total_time;
    if (is_red) 
    {
        if (cur_time >= red_time)
        {
            is_red = false;
            //change image to green
            if (TrafficLight::redLight == nullptr) {
                TrafficLight::redLight = new sf::Texture();
                TrafficLight::redLight->loadFromFile(green_light_filename);
            }
            sprite.setTexture(*TrafficLight::redLight);
        }
    }
    else 
        if (cur_time < red_time)
        {
            is_red = true;
            //change image to red
            if (TrafficLight::greenLight == nullptr) {
                TrafficLight::greenLight = new sf::Texture();
                TrafficLight::greenLight->loadFromFile(red_light_filename);
            }
            sprite.setTexture(*TrafficLight::greenLight);
        }
}

void TrafficLight::draw()
{
    sf::RenderWindow *window = Factory::getRenderWindow();
    window->draw(sprite);
}

bool TrafficLight::isRed()
{
    return this->is_red;
}