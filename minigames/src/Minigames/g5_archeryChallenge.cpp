//binary search

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime> // for time(0)
using namespace std;

// Function to simulate a binary search shot
int binarySearchShot(int target, int maxRange) {
    int left = 0, right = maxRange, attempts = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        attempts++;
        if (mid == target) {
            return attempts;  // Target hit
        } else if (mid < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // Target missed (should not happen in binary search)
}

// Archery minigame
void archeryGame(int maxRange, int shots) {
    srand(time(0)); // Seed the random number generator
    vector<int> targets(shots);

    // Generate random targets
    for (int i = 0; i < shots; i++) {
        targets[i] = rand() % maxRange + 1;
    }

    int score = 0;
    for (int i = 0; i < shots; i++) {
        int target = targets[i];
        cout << "Target at distance " << target << ". Aim and hit it!\n";
        int attempts = binarySearchShot(target, maxRange);

        if (attempts > 0) {
            int points = maxRange / attempts;
            cout << "Hit in " << attempts << " attempts! Points: " << points << endl;
            score += points;
        } else {
            cout << "Missed the target.\n";
        }
    }
    cout << "Total Score: " << score << endl;
}

int main() {
    int maxRange = 100;  // Max distance for targets
    int shots = 3;       // Number of targets
    archeryGame(maxRange, shots);
    return 0;
}
