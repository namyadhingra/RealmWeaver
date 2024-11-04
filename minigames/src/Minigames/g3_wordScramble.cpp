//words are scrambled, and the player needs to sort them alphabetically
//sorting algorithms are used here for array manipulation

// The player is given a scrambled word list. They sort the characters of each word correctly to complete the minigame.
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

// Word Scramble minigame
void wordScramble(const vector<string>& words) {
    vector<string> scrambled = scrambleWords(words);
    int score = 0;

    for (size_t i = 0; i < words.size(); i++) {
        cout << "Unscramble this word: " << scrambled[i] << endl;
        string guess;
        cin >> guess;

        sort(guess.begin(), guess.end());
        string sortedWord = words[i];
        sort(sortedWord.begin(), sortedWord.end());

        if (guess == sortedWord) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Incorrect. The correct word was: " << words[i] << endl;
        }
    }
    cout << "You scored: " << score << " out of " << words.size() << endl;
}

int main() {
    srand(time(0));
    vector<string> words = {"apple", "banana", "cherry"};
    wordScramble(words);
    return 0;
}
