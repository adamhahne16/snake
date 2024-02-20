#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include "Border.h"
#include <vector>



class Snake {
private:

	struct SnakeSegment {
		sf::RectangleShape shape;
		SnakeSegment(float x, float y);
	};
	bool hasGrown;
	std::vector<SnakeSegment> segments;
	sf::Vector2f saveDirection;

public: 
	Snake();
	void move(sf::Vector2f direction);
	void grow();
	void draw(sf::RenderWindow& window);
	bool checkCollisionWithBorder(const Border& border);
	bool checkSelfCollision();
	void reset();
	std::vector<Snake::SnakeSegment> getSegments();

	

};


#endif
