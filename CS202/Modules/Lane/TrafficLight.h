#ifndef _TrafficLight_H_
#define _TrafficLight_H_

#include <vector>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>

class TrafficLight
{
private:
    bool is_red;
    int red_time, total_time; //in millisecond
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
};

#endif