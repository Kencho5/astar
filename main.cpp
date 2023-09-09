#include </opt/homebrew/Cellar/sfml/2.5.1_2/include/SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>

class Screen {
public:
  static const int width = 1920;
  static const int height = 1080;
};

class Grid {
private:
  static const int size = 50;

  static const int width = Screen::width / size;
  static const int height = Screen::height / size;
  int grid[width][height];

public:
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
        shape.setFillColor(sf::Color::White);
        shape.setOutlineThickness(5);
        shape.setOutlineColor(sf::Color::Black);

        shape.setPosition(i * size, j * size);
        window.draw(shape);
      }
    }
  }

  void setBlock() {}
};

int main() {
  sf::RenderWindow window(sf::VideoMode(Screen::width, Screen::height),
                          "a* pathfinding");

  Grid grid;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed ||
          event.key.code == sf::Keyboard::Escape) {
        window.close();
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
