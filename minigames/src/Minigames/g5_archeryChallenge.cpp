//binary search
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// Function to simulate a binary search shot
int binarySearchShot(int target, int maxRange, int& currentGuess) {
    int left = 0, right = maxRange, attempts = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        currentGuess = mid;
        attempts++;
        if (mid == target) {
            return attempts;  // Target hit
        } else if (mid < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // Target missed
}

// Archery minigame with SFML
void archeryGame(int maxRange, int shots) {
    srand(time(0));
    vector<int> targets(shots);
    for (int i = 0; i < shots; i++) {
        targets[i] = rand() % maxRange + 1;
    }

    int score = 0;
    int currentGuess = 0;
    int targetIndex = 0;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Archery Minigame");
    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text targetText, guessText, feedbackText, scoreText;
    targetText.setFont(font);
    targetText.setCharacterSize(30);
    targetText.setFillColor(sf::Color::White);
    targetText.setPosition(50, 50);

    guessText.setFont(font);
    guessText.setCharacterSize(30);
    guessText.setFillColor(sf::Color::Yellow);
    guessText.setPosition(50, 100);

    feedbackText.setFont(font);
    feedbackText.setCharacterSize(30);
    feedbackText.setFillColor(sf::Color::Green);
    feedbackText.setPosition(50, 150);

    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::Cyan);
    scoreText.setPosition(50, 200);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    // Simulate binary search attempt on space press
                    int attempts = binarySearchShot(targets[targetIndex], maxRange, currentGuess);
                    if (attempts > 0) {
                        int points = maxRange / attempts;
                        feedbackText.setString("Hit! Attempts: " + to_string(attempts) + " Points: " + to_string(points));
                        score += points;
                        targetIndex++;
                        if (targetIndex >= shots) {
                            window.close();
                        }
                    } else {
                        feedbackText.setString("Missed the target.");
                    }
                }
            }
        }

        // Update texts
        targetText.setString("Target Distance: " + to_string(targets[targetIndex]));
        guessText.setString("Current Guess: " + to_string(currentGuess));
        scoreText.setString("Total Score: " + to_string(score));

        window.clear();
        window.draw(targetText);
        window.draw(guessText);
        window.draw(feedbackText);
        window.draw(scoreText);
        window.display();
    }
}

int main() {
    int maxRange = 100;
    int shots = 3;
    archeryGame(maxRange, shots);
    return 0;
}
