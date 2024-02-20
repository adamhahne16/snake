#include "menu.h"

Menu::Menu(float width, float height) {
    if (!font.loadFromFile("C:/Users/Hahne/Desktop/c++prog/snakegame/font/Freedom-10eM.ttf")) {
        // Handle error
    }
    unsigned int fontSize = 30;
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::White);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (2 + 1) * 1));
    menu[0].setCharacterSize(fontSize);

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Exit");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (2 + 1) * 2));
    menu[1].setCharacterSize(fontSize);

    selectedItemIndex = 0;
}

Menu::~Menu() {
}

void Menu::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 2; i++) {
        window.draw(menu[i]);
    }
}

void Menu::MoveDown() {
    if (selectedItemIndex - 1 >= 0) {
        menu[selectedItemIndex].setFillColor(sf::Color::Blue);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::White);
    }
}

void Menu::MoveUp() {
    if (selectedItemIndex + 1 < 2) {
        menu[selectedItemIndex].setFillColor(sf::Color::Blue);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::White);
    }
}
