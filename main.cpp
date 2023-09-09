#include </opt/homebrew/Cellar/sfml/2.5.1_2/include/SFML/Graphics.hpp>

int main() {
  sf::Window window(sf::VideoMode(1920, 1080), "a*");

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed ||
          event.key.code == sf::Keyboard::Escape)
        window.close();
    }
  }

  return 0;
}

// g++ main.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_2/include -o app
// -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window
// -lsfml-system && ./app
