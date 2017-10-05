//
// Created by benji on 04.10.17.
//

#include "Button.h"

sf::Font* Button::font = NULL;
sf::Texture* Button::texture = NULL;

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(*m_sprite, states);
    target.draw(*m_text, states);
}

Button::Button(const std::string &string, const sf::Vector2f &position) : m_position(position) {
    if(!font){
        font = new sf::Font();
        font->loadFromFile("../SCRIPTIN.ttf");
    }

    if(!texture){
        texture = new sf::Texture();
        texture->loadFromFile("../button.png");
    }

    m_sprite->setTexture(*texture);
    m_sprite->setPosition(position);
    m_text->setFont(*font);
    m_text->setColor({0,255,0});
    m_text->setString(string);
    m_text->setPosition(position);
}
