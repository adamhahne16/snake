#include "Border.h"

Border::Border(float width, float height) {
	float thickness = 0.5f;

	// Initialisera varje sida av ramen
	top.setSize(sf::Vector2f(width, thickness));
	bottom.setSize(sf::Vector2f(width, thickness));
	left.setSize(sf::Vector2f(thickness, height));
	right.setSize(sf::Vector2f(thickness, height));

	// Positionera varje sida
	top.setPosition(0, 0);
	bottom.setPosition(0, height - thickness);
	left.setPosition(0, 0);
	right.setPosition(width - thickness, 0);

	// Ange färg
	sf::Color color = sf::Color::Blue;
	top.setFillColor(color);
	bottom.setFillColor(color);
	left.setFillColor(color);
	right.setFillColor(color);
}

void Border::draw(sf::RenderWindow& window) {
	window.draw(top);
	window.draw(bottom);
	window.draw(left);
	window.draw(right);
}
