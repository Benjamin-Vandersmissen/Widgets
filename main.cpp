#include <iostream>

#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "Button.h"
int main() {

    std::vector<Button*> buttons = {new Button("TEST TEST \n lol", {20,20})}; //Create a button
    //Set a function as callback
//    buttons[0]->setFunction(test, new std::string("BBB"));

    //create a new window with size 400x400
    sf::RenderWindow window(sf::VideoMode(400,400),"TEST");
    while (window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            //check for events
            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseButtonPressed:
                    //Mouse pressed => check each button
                    for(Button* button : buttons){
                        button->clicked(event);
                    }
                    break;
            }
        }
        //clear the window
        window.clear();

        //draw each button
        for(Button* b : buttons){
            window.draw(*b);
        }

        //display the window
        window.display();
    }
    return 0;
}