#include </opt/homebrew/Cellar/sfml/2.5.1_2/include/SFML/Graphics.hpp>

int main() {
  sf::Window window(sf::VideoMode(800, 600), "a*");

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
  }

  return 0;
}

// g++ main.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_2/include -o app
// -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window
// -lsfml-system && ./app
