#include </opt/homebrew/Cellar/sfml/2.5.1_2/include/SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>

class Grid {
private:
  static const int width = 10, height = 10;
  int grid[width][height];

public:
  const int size = 35;

  Grid() {
    for (int i = 0; i < width; i++) {
      for (int j = 0; j < height; j++) {
        grid[i][j] = 0;
      }
    }
  }

  void draw(sf::RenderWindow &window) {}
};

int main() {
  sf::RenderWindow window(sf::VideoMode(2520, 1470), "a* pathfinding");

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
