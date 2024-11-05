//Dynamic programming
#include <SFML/Graphics.hpp>
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

// Maze Runner minigame with SFML
void mazeRunner() {
    int n = 4;  // Maze size
    vector<vector<int>> maze = {
        {1, 3, 1, 5},
        {2, 1, 3, 2},
        {4, 2, 1, 7},
        {2, 1, 2, 1}
    };

    sf::RenderWindow window(sf::VideoMode(800, 800), "Maze Runner Game");
    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text minPathText;
    minPathText.setFont(font);
    minPathText.setCharacterSize(30);
    minPathText.setFillColor(sf::Color::White);
    minPathText.setPosition(50, 50);

    // Drawing the maze grid
    int cellSize = 150;
    vector<sf::RectangleShape> cells;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
            cell.setFillColor(sf::Color(100, 100, 250));
            cell.setOutlineThickness(2);
            cell.setOutlineColor(sf::Color::Black);
            cell.setPosition(j * cellSize + 50, i * cellSize + 100);

            cells.push_back(cell);
        }
    }

    // Minimum path cost calculation
    int minPathCost = minPathDP(maze, n);
    minPathText.setString("Minimum cost to reach the end: " + to_string(minPathCost));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (auto& cell : cells) {
            window.draw(cell);
        }
        window.draw(minPathText);
        window.display();
    }
}

int main() {
    mazeRunner();
    return 0;
}
