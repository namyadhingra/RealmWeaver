//using Heaps/Priority Queue

#include <iostream>
#include <queue>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Mole {
    int id;
    int points;  // Higher points indicate higher priority
    Mole(int i, int p) : id(i), points(p) {}
};

// Comparator for the max heap
struct Compare {
    bool operator()(const Mole& m1, const Mole& m2) {
        return m1.points < m2.points;
    }
};

// Whack-a-Mole game
void whackAMole(int numMoles) {
    priority_queue<Mole, vector<Mole>, Compare> moles;
    srand(time(0));
    
    // Randomly add moles to the heap
    for (int i = 0; i < numMoles; i++) {
        int points = rand() % 100 + 1;
        moles.push(Mole(i, points));
    }

    int score = 0;
    while (!moles.empty()) {
        Mole mole = moles.top();
        moles.pop();
        cout << "Mole with ID: " << mole.id << " and Points: " << mole.points << " appeared! Whack? (y/n): ";
        
        char choice;
        cin >> choice;
        
        if (choice == 'y' || choice == 'Y') {
            score += mole.points;
            cout << "You whacked it! Score: " << score << endl;
        } else {
            cout << "Missed that one.\n";
        }
    }
    cout << "Final Score: " << score << endl;
}

int main() {
    int numMoles = 5;  // Total moles to appear
    whackAMole(numMoles);
    return 0;
}
