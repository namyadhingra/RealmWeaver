//words are scrambled, and the player needs to sort them alphabetically
//sorting algorithms are used here for array manipulation

// The player is given a scrambled word list. They sort the characters of each word correctly to complete the minigame.
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

// Function to scramble words
vector<string> scrambleWords(const vector<string>& words) {
    vector<string> scrambled = words;
    for (string& word : scrambled) random_shuffle(word.begin(), word.end());
    return scrambled;
}

// Word Scramble minigame with SFML
void wordScramble(const vector<string>& words) {
    vector<string> scrambled = scrambleWords(words);
    int score = 0;
    string guess;

    sf::RenderWindow window(sf::VideoMode(600, 400), "Word Scramble Game");
    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text scrambledWordText;
    scrambledWordText.setFont(font);
    scrambledWordText.setCharacterSize(30);
    scrambledWordText.setFillColor(sf::Color::White);
    scrambledWordText.setPosition(50, 50);

    sf::Text feedbackText;
    feedbackText.setFont(font);
    feedbackText.setCharacterSize(24);
    feedbackText.setFillColor(sf::Color::Green);
    feedbackText.setPosition(50, 150);

    sf::Text inputText;
    inputText.setFont(font);
    inputText.setCharacterSize(30);
    inputText.setFillColor(sf::Color::Yellow);
    inputText.setPosition(50, 250);

    size_t wordIndex = 0;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b') { // Handle backspace
                    if (!guess.empty()) guess.pop_back();
                } else if (event.text.unicode == '\r') { // Handle enter key
                    // Sort and compare the guess with the original word
                    string sortedGuess = guess;
                    sort(sortedGuess.begin(), sortedGuess.end());
                    string sortedWord = words[wordIndex];
                    sort(sortedWord.begin(), sortedWord.end());

                    if (sortedGuess == sortedWord) {
                        feedbackText.setString("Correct!");
                        score++;
                    } else {
                        feedbackText.setString("Incorrect. The word was: " + words[wordIndex]);
                    }

                    guess.clear();
                    wordIndex++;
                    if (wordIndex >= words.size()) {
                        window.close();
                    }
                } else {
                    guess += static_cast<char>(event.text.unicode); // Add typed character to guess
                }
            }
        }

        // Update the scrambled word and input display
        scrambledWordText.setString("Unscramble this word: " + scrambled[wordIndex]);
        inputText.setString("Your guess: " + guess);

        window.clear();
        window.draw(scrambledWordText);
        window.draw(feedbackText);
        window.draw(inputText);
        window.display();
    }

    cout << "You scored: " << score << " out of " << words.size() << endl;
}

int main() {
    srand(time(0));
    vector<string> words = {"apple", "banana", "cherry"};
    wordScramble(words);
    return 0;
}
