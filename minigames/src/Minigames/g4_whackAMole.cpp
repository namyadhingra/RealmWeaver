//using Heaps/Priority Queue
#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Mole {
    int id;
    int points;
    sf::CircleShape shape;  // Represent the mole as a circle

    Mole(int i, int p, sf::Vector2f position) : id(i), points(p) {
        shape.setRadius(50);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(position);
    }
};

// Comparator for the max heap
struct Compare {
    bool operator()(const Mole& m1, const Mole& m2) {
        return m1.points < m2.points;
    }
};

// Whack-a-Mole game with SFML
void whackAMole(int numMoles) {
    priority_queue<Mole, vector<Mole>, Compare> moles;
    srand(time(0));

    sf::RenderWindow window(sf::VideoMode(800, 600), "Whack-a-Mole Game");
    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    int score = 0;
    scoreText.setString("Score: " + to_string(score));

    // Randomly place moles in the window
    for (int i = 0; i < numMoles; i++) {
        int points = rand() % 100 + 1;
        sf::Vector2f position(rand() % 700, rand() % 500);
        moles.push(Mole(i, points, position));
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (!moles.empty()) {
                    Mole topMole = moles.top();
                    if (topMole.shape.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                        score += topMole.points;
                        moles.pop();
                    }
                }
            }
        }

        window.clear();

        // Draw remaining moles
        if (!moles.empty()) {
            Mole topMole = moles.top();
            window.draw(topMole.shape);
        }

        scoreText.setString("Score: " + to_string(score));
        window.draw(scoreText);
        window.display();

        // Check if game is over
        if (moles.empty()) {
            cout << "Final Score: " << score << endl;
            window.close();
        }
    }
}

int main() {
    int numMoles = 5;  // Total moles to appear
    whackAMole(numMoles);
    return 0;
}
