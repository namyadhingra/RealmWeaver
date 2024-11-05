//using BFS/DFS
#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 5;
int maze[N][N] = { {1, 1, 0, 1, 1},
                   {0, 1, 0, 1, 0},
                   {1, 1, 1, 0, 1},
                   {1, 0, 0, 1, 1},
                   {1, 1, 1, 1, 9} }; // 9 is treasure

struct Point {
    int x, y;
};

bool isValid(int x, int y, vector<vector<bool>>& visited) {
    return x >= 0 && x < N && y >= 0 && y < N && maze[x][y] != 0 && !visited[x][y];
}

int findTreasure(Point start, sf::RenderWindow& window, sf::RectangleShape& player) {
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<pair<Point, int>> q;
    q.push({start, 0});
    visited[start.x][start.y] = true;

    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
        Point pt = q.front().first;
        int steps = q.front().second;
        q.pop();

        player.setPosition(pt.y * 80, pt.x * 80);
        window.clear();
        window.draw(player);
        window.display();

        if (maze[pt.x][pt.y] == 9) return steps;

        for (auto dir : directions) {
            int newX = pt.x + dir[0];
            int newY = pt.y + dir[1];

            if (isValid(newX, newY, visited)) {
                visited[newX][newY] = true;
                q.push({{newX, newY}, steps + 1});
            }
        }
    }
    return -1;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 400), "Maze Treasure Hunt");

    sf::RectangleShape player(sf::Vector2f(80, 80));
    player.setFillColor(sf::Color::Red);

    Point start = {0, 0};
    int result = findTreasure(start, window, player);

    if (result != -1)
        cout << "Treasure found in " << result << " steps!\n";
    else
        cout << "No treasure found.\n";

    return 0;
}
