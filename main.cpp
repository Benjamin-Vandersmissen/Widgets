#include <iostream>

#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "Button.h"
int main() {

    std::vector<Button*> buttons = {new Button("TEST", {20,20})};
    sf::RenderWindow window(sf::VideoMode(400,400),"TEST");
    while (window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseButtonPressed:

                    break;
            }
        }
        window.clear();
        for(Button* b : buttons){
            window.draw(*b);
        }
        window.display();
//        window.draw()
    }
    return 0;
}