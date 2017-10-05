//
// Created by benji on 04.10.17.
//

#include <iostream>
#include "Button.h"

sf::Font* Button::font = NULL;
sf::Texture* Button::texture = NULL;

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(*m_sprite, states);
    target.draw(*m_text, states);
}

Button::Button(const std::string &string, const sf::Vector2f &position) : m_position(position) {
    if(!font){ //if no font is loaded yet, load the font
        font = new sf::Font();
        font->loadFromFile("../calibri.ttf");
    }

    if(!texture){ //if no texture is loaded yet, load the texture
        texture = new sf::Texture();
        texture->loadFromFile("../button.png");
    }

    //set the sprite
    m_sprite->setTexture(*texture);
    m_sprite->setPosition(position);

    //set the text
    m_text->setFont(*font);
    m_text->setString(string);
    m_text->setPosition(position);

    //resizeButton
    resizeButton();
}

void Button::resizeButton() {
    float offset = 10;
    float desiredWidth = m_text->getGlobalBounds().width+offset;
    float desiredHeight = m_text->getGlobalBounds().height+offset;

    //move the sprite to the correct position
    m_sprite->setPosition(m_sprite->getPosition().x-offset/2, m_text->getGlobalBounds().top-offset/2);

    float idealHorScale = desiredWidth/m_sprite->getGlobalBounds().width;
    float idealVertScale = desiredHeight/m_sprite->getGlobalBounds().height;

    //scale the sprite to the correct width - and height
    m_sprite->setScale(idealHorScale, idealVertScale);
}

bool Button::contains(sf::Vector2f position) {
    return m_sprite->getGlobalBounds().contains(position);
}

bool Button::clicked(sf::Event &event) {
    //check if a button was pressed
    if(event.type == sf::Event::MouseButtonPressed){
        //check if the cursor is over the button
        if(contains({event.mouseButton.x, event.mouseButton.y})){
            //check if the left button is presssed
            if(event.mouseButton.button == sf::Mouse::Button::Left){
                if(func != nullptr) //check if a callback is set
                    func(args);
                return true;
            }
        }
    }
    return false;
}

void Button::setFunction(void (*function)(void *), void *args) {
    func = function;
    this->args = args;
}

void test(void *v) {
    std::cout <<"AAAAA" << *(std::string*)v <<std::endl;
}
