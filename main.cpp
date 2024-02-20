#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include "menu.h"
#include "Border.h"
#include "Snake.h"
#include "Food.h"
#include "GameState.h"



int main()
{
	//create window
	sf::RenderWindow window(sf::VideoMode(640, 480), "dt047g PROJECT SNAKE!", sf::Style::Titlebar | sf::Style::Close);
	GameState state = MENU;
	Menu menu(window.getSize().x, window.getSize().y);
	Border border(window.getSize().x, window.getSize().y);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);


	Snake snake;
	sf::Vector2f direction(20.f, 0.f); // Initial rörelseriktning till höger

	sf::Clock clock;
	const float updateMS = 100.f;
	Food food;



	//game
	while (window.isOpen()) {
		sf::Event ev;
		while (window.pollEvent(ev)) {
			if (ev.type == sf::Event::Closed) {
				window.close();
			}

			if (state == MENU) {
				if (ev.type == sf::Event::KeyPressed) {
					if (ev.key.code == sf::Keyboard::Up) {
						menu.MoveUp();
					}
					else if (ev.key.code == sf::Keyboard::Down) {
						menu.MoveDown();
					}
					else if (ev.key.code == sf::Keyboard::Enter) {
						// If "Play" selected, start the game
						if (menu.GetPressedItem() == 1) { // "Play" is the first item
							state = GAME;
						}
						else if (menu.GetPressedItem() == 0) { // "Exit" is the second item
							window.close();
						}
					}
				}
			}
		}

		window.clear(sf::Color::Green); // Clear the window with green background

		if (state == MENU) {
			menu.draw(window);
		}
		else if (state == GAME) {
			// Handle game input only when in GAME state
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) direction = sf::Vector2f(0.f, -20.f);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) direction = sf::Vector2f(0.f, 20.f);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) direction = sf::Vector2f(-20.f, 0.f);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) direction = sf::Vector2f(20.f, 0.f);

			// Update the game with a set speed
			if (clock.getElapsedTime().asMilliseconds() >= updateMS) {
				snake.move(direction);
				clock.restart();
			}

			border.draw(window);
			window.draw(food.getShape());
			snake.draw(window); // Draw the snake

			if (snake.getSegments()[0].shape.getGlobalBounds().intersects(food.getShape().getGlobalBounds())) {
				food = Food(); // Generate new food
				snake.grow(); // Let the snake grow
			}
			if (snake.checkCollisionWithBorder(border)) {
				state = MENU; // Ändra tillstånd till MENU
				snake.reset();
				
			}
			if (snake.checkSelfCollision()) {
				state = MENU; // Ändra tillstånd till MENU
				snake.reset(); // Återställ ormen till starttillstånd
			}

		}

		window.display(); // Display the window contents
	}

	return 0;
}
