//
// Created by benji on 04.10.17.
//

#include "Button.h"

sf::Font* ButtonFont = new sf::Font();

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const{

}

Button::Button(sf::Sprite *sprite, const std::string &text, const sf::Vector2f &position) : sprite(sprite), text(text),
                                                                                            position(position) {
    sf::Text*
}
