#ifndef BORDER_H
#define BORDER_H
#include <SFML/Graphics.hpp>

class Border {
public:
	Border(float width, float height);
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape top, bottom, left, right;
};

#endif // !BORDER_H

