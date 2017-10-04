//
// Created by benji on 04.10.17.
//

#ifndef WIDGETS_BUTTON_H
#define WIDGETS_BUTTON_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

class Button : public sf::Drawable{
private:
    bool value = true;

    sf::Sprite* sprite;

    std::string text;

    sf::Vector2f position;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    Button(sf::Sprite *sprite, const std::string &text, const sf::Vector2f &position);

};


#endif //WIDGETS_BUTTON_H
