#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;
namespace py = pybind11;

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

string memoryGame(int n) {
    vector<int> cards = generateCards(n);
    stack<int> flipStack;
    vector<bool> revealed(2 * n, false);
    int matches = 0;
    string output;

    while (matches < n) {
        int pos;
        output += "Choose a card to flip (0 to " + to_string(2 * n - 1) + "): ";
        cin >> pos;

        if (revealed[pos]) {
            output += "Card already revealed!\n";
            continue;
        }

        flipStack.push(pos);
        revealed[pos] = true;
        output += "Card flipped: " + to_string(cards[pos]) + "\n";

        if (flipStack.size() == 2) {
            int top1 = flipStack.top();
            flipStack.pop();
            int top2 = flipStack.top();
            flipStack.pop();

            if (cards[top1] == cards[top2]) {
                output += "Match found!\n";
                matches++;
            } else {
                output += "Not a match. Try again.\n";
                revealed[top1] = revealed[top2] = false;
            }
        }
    }
    output += "Congratulations! You've matched all cards.\n";
    return output;
}