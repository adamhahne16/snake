#include "Snake.h"



// SnakeSegment konstruktor
Snake::SnakeSegment::SnakeSegment(float x, float y) {
    shape.setSize(sf::Vector2f(20.f, 20.f)); // Storleken på varje segment
    shape.setFillColor(sf::Color::Blue); // Färgen på segmenten
    shape.setPosition(x, y); // Positionen för segmentet
}

// Snake konstruktor
Snake::Snake() : hasGrown(false), saveDirection(20.f, 0.f) {
    // Startstorlek (startsegment)
    segments.emplace_back(100.f, 100.f); // Använder emplace_back för effektivitet
}

// Rör på ormen i angiven riktning
void Snake::move(sf::Vector2f direction) {
    // Beräkna ny position för ormens huvud baserat på riktningen
    sf::Vector2f newHeadPosition = segments.front().shape.getPosition() + direction;
    // Lägg till ett nytt segment i början av listan för att representera det nya huvudet
    segments.insert(segments.begin(), SnakeSegment(newHeadPosition.x, newHeadPosition.y));

    // Om ormen inte har vuxit, ta bort det sista segmentet för att behålla samma längd
    if (!hasGrown) {
        segments.pop_back();
    }
    else {
        hasGrown = false; // Återställer hasGrown för nästa rörelse
    }

    saveDirection = direction; // Sparar den senaste riktningen
}

// Låter ormen växa
void Snake::grow() {
    hasGrown = true;
}

// Ritar ormen på fönstret
void Snake::draw(sf::RenderWindow& window) {
    for (auto& segment : segments) {
        window.draw(segment.shape);
    }
}

// Kontrollerar kollision med gränsen
bool Snake::checkCollisionWithBorder(const Border& border) {
    auto headPos = segments.front().shape.getPosition();

    if (headPos.x < 0 || headPos.x >= 640 || headPos.y < 0 || headPos.y >= 480) {
        return true; // Det finns en kollision
    }

    return false; // Ingen kollision
}

// Kontrollerar om ormen kolliderar med sig själv
bool Snake::checkSelfCollision() {
    for (size_t i = 1; i < segments.size(); ++i) {
        if (segments[0].shape.getGlobalBounds().intersects(segments[i].shape.getGlobalBounds())) {
            return true; // Det finns en kollision
        }
    }
    return false; // Ingen kollision
}

// Återställer ormen till sitt starttillstånd
void Snake::reset() {
    segments.clear(); // Rensar alla segment
    segments.emplace_back(100.f, 100.f); // Återlägger startsegmentet
    saveDirection = sf::Vector2f(20.f, 0.f); // Återställer riktningen
    hasGrown = false; // Återställer tillväxtflaggan
}

// Returnerar en lista över ormens segment
std::vector<Snake::SnakeSegment> Snake::getSegments() {
    return segments;
}
