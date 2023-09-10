#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>

class Screen {
public:
  static const int width = 1920;
  static const int height = 1080;

  static const int size = 50;
};

class Grid {
private:
  static const int width = Screen::width / Screen::size;
  static const int height = Screen::height / Screen::size;
  int grid[width][height];

public:
  int size = Screen::size;

  Grid() {
    for (int i = 0; i < width; i++) {
      for (int j = 0; j < height; j++) {
        grid[i][j] = 0;
      }
    }
  }

  void draw(sf::RenderWindow &window) {
    for (int i = 0; i < width; i++) {
      for (int j = 0; j < height; j++) {
        sf::RectangleShape shape = sf::RectangleShape();
        shape.setSize(sf::Vector2f(size, size));
        shape.setOutlineThickness(5);
        shape.setOutlineColor(sf::Color::Black);

        switch (grid[i][j]) {
        case 0:
          shape.setFillColor(sf::Color::White);
          break;
        case 1:
          shape.setFillColor(sf::Color::Blue);
          break;
        case 2:
          shape.setFillColor(sf::Color::Red);
          break;
        case 3:
          shape.setFillColor(sf::Color::Black);
          break;
        }

        shape.setPosition(i * size, j * size);
        window.draw(shape);
      }
    }
  }

  void setBlock(int x, int y, int type) {
    switch (type) {
    case 1:
      grid[x][y] = 1;
      break;
    case 2:
      grid[x][y] = 2;
      break;
    case 3:
      grid[x][y] = 3;
      break;
    }
  }
};

int main() {
  sf::RenderWindow window(
      sf::VideoMode(floor(Screen::width), floor(Screen::height)),
      "a* pathfinding");

  Grid grid;
  int size = Screen::size;
  int type;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape)
          window.close();
        if (event.type == sf::Event::Closed)
          window.close();

        if (event.key.code == sf::Keyboard::S)
          type = 1;
        else if (event.key.code == sf::Keyboard::E)
          type = 2;
        else if (event.key.code == sf::Keyboard::W)
          type = 3;
      }
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i position = sf::Mouse::getPosition(window);

        int gridX = floor(position.x / size);
        int gridY = floor(position.y / size);
        grid.setBlock(gridX, gridY, type);
      }

      window.clear();
      grid.draw(window);
      window.display();
    }
  }

  return 0;
}

// g++ main.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_2/include -o app
// -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window
// -lsfml-system && ./app
