#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

vector<int> generateCards(int n) {
    vector<int> cards;
    for (int i = 1; i <= n; i++) {
        cards.push_back(i);
        cards.push_back(i);
    }

    random_device rd;
    mt19937 g(rd());
    shuffle(cards.begin(), cards.end(), g);

    return cards;
}

int main() {
    int n = 4;  // Number of pairs
    vector<int> cards = generateCards(n);
    stack<int> flipStack;
    vector<bool> revealed(2 * n, false);
    int matches = 0;

    sf::RenderWindow window(sf::VideoMode(600, 400), "Memory Card Matching Game");
    sf::Font font;
    font.loadFromFile("arial.ttf");

    vector<sf::RectangleShape> cardShapes(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cardShapes[i].setSize(sf::Vector2f(80, 120));
        cardShapes[i].setFillColor(sf::Color::Green);
        cardShapes[i].setPosition(100 * (i % n), 120 * (i / n));
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int i = 0; i < 2 * n; i++) {
            if (revealed[i]) {
                sf::Text cardNumber;
                cardNumber.setFont(font);
                cardNumber.setString(to_string(cards[i]));
                cardNumber.setCharacterSize(24);
                cardNumber.setFillColor(sf::Color::Black);
                cardNumber.setPosition(cardShapes[i].getPosition().x + 30, cardShapes[i].getPosition().y + 40);
                window.draw(cardShapes[i]);
                window.draw(cardNumber);
            } else {
                window.draw(cardShapes[i]);
            }
        }

        window.display();

        if (matches == n) {
            // Display message and close the window
            cout << "Congratulations! You've matched all cards.\n";
            window.close();
        }

        // Implement SFML-based interaction here, where mouse click flips the cards
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            for (int i = 0; i < 2 * n; i++) {
                if (cardShapes[i].getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && !revealed[i]) {
                    flipStack.push(i);
                    revealed[i] = true;
                    if (flipStack.size() == 2) {
                        int first = flipStack.top();
                        flipStack.pop();
                        int second = flipStack.top();
                        flipStack.pop();
                        if (cards[first] == cards[second]) {
                            matches++;
                        } else {
                            revealed[first] = false;
                            revealed[second] = false;
                        }
                    }
                    break;
                }
            }
        }
    }

    return 0;
}
