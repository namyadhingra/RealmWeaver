//with UI
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

const int width = 20;
const int height = 20;
const int scale = 25; // Scale for each cell in the UI
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
bool gameOver;
enum eDirection { STOP=0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Draw(sf::RenderWindow &window) {
    window.clear();

    // Draw boundaries
    sf::RectangleShape border(sf::Vector2f((width + 2) * scale, (height + 2) * scale));
    border.setFillColor(sf::Color::Black);
    window.draw(border);

    // Draw fruit
    sf::RectangleShape fruit(sf::Vector2f(scale, scale));
    fruit.setFillColor(sf::Color::Red);
    fruit.setPosition(fruitX * scale, fruitY * scale);
    window.draw(fruit);

    // Draw snake head
    sf::RectangleShape snakeHead(sf::Vector2f(scale, scale));
    snakeHead.setFillColor(sf::Color::Green);
    snakeHead.setPosition(x * scale, y * scale);
    window.draw(snakeHead);

    // Draw snake tail
    sf::RectangleShape snakeTail(sf::Vector2f(scale, scale));
    snakeTail.setFillColor(sf::Color::Yellow);
    for (int i = 0; i < nTail; i++) {
        snakeTail.setPosition(tailX[i] * scale, tailY[i] * scale);
        window.draw(snakeTail);
    }

    // Display score
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cout << "Failed to load font!" << endl;
    }
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setString("Score: " + to_string(score));
    scoreText.setPosition(10, (height + 1) * scale);
    window.draw(scoreText);

    window.display();
}

void Input() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && dir != RIGHT)
        dir = LEFT;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && dir != LEFT)
        dir = RIGHT;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && dir != DOWN)
        dir = UP;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && dir != UP)
        dir = DOWN;
}

void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case LEFT:  x--; break;
        case RIGHT: x++; break;
        case UP:    y--; break;
        case DOWN:  y++; break;
        default:    break;
    }

    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            gameOver = true;
            break;
        }
    }

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

int main() {
    srand(time(0)); // Seed random for fruit generation
    Setup();

    // Create a window
    sf::RenderWindow window(sf::VideoMode(width * scale, (height + 2) * scale), "Snake Game");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (!gameOver) {
            Input();
            Logic();
            Draw(window);
        } else {
            window.clear();
            sf::Font font;
            if (font.loadFromFile("arial.ttf")) {
                sf::Text gameOverText("Game Over! Score: " + to_string(score), font, 30);
                gameOverText.setFillColor(sf::Color::Red);
                gameOverText.setPosition((width - 5) * scale / 2, (height / 2) * scale);
                window.draw(gameOverText);
                window.display();
                sf::sleep(sf::seconds(3));
                window.close();
            }
        }
        sf::sleep(sf::milliseconds(100));  // Game speed control
    }
    return 0;
}
