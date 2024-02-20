#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>

class Food {
private:
    sf::CircleShape shape;

public:
    Food();
    sf::CircleShape getShape();
};

#endif // FOOD_H
