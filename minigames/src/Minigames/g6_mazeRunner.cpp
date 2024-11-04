#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to calculate minimum path sum using DP
int minPathDP(vector<vector<int>>& maze, int n) {
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    dp[0][0] = maze[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + maze[i][j]);
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + maze[i][j]);
        }
    }
    return dp[n-1][n-1];
}

// Maze Runner minigame
void mazeRunner() {
    int n = 4;  // Maze size
    vector<vector<int>> maze = {
        {1, 3, 1, 5},
        {2, 1, 3, 2},
        {4, 2, 1, 7},
        {2, 1, 2, 1}
    };

    cout << "Maze Grid:\n";
    for (auto row : maze) {
        for (auto cell : row) cout << cell << " ";
        cout << endl;
    }

    int result = minPathDP(maze, n);
    cout << "Minimum cost to reach the end: " << result << endl;
}

int main() {
    mazeRunner();
    return 0;
}
