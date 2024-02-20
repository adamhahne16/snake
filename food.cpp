#include "Food.h"

Food::Food() {
    int maxX = (640 / 20) - 1;
    int maxY = (480 / 20) - 1;
    int x = (rand() % maxX) * 20; // Genererar en multippel av 20
    int y = (rand() % maxY) * 20;
    shape.setRadius(10.f);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(x, y);
}

sf::CircleShape Food::getShape() {
    return shape;
}
