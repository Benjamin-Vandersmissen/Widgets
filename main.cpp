#include <iostream>

#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
int main() {
    std::cout << "Hello, World!" << std::endl;

    sf::RenderWindow window;
    while (window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        window.clear();

        window.display();
        window.draw()
    }
    return 0;
}