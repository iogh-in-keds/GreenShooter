#include "World.h"
#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    srand(time(NULL));
    RenderWindow window(sf::VideoMode(900, 900), "Game");
    window.setFramerateLimit(100);
    World world;
    while (window.isOpen()) {
        Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        world.Event(window, event);
    }
    return 0;
}