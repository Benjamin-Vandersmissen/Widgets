//
// Created by benji on 04.10.17.
//

#ifndef WIDGETS_BUTTON_H
#define WIDGETS_BUTTON_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

class Button : public sf::Drawable{
private:
    static sf::Texture* texture;

    static sf::Font* font;

    bool pressed = false;

    sf::Sprite* m_sprite = new sf::Sprite();

    sf::Text* m_text = new sf::Text();

    sf::Vector2f m_position;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    Button(const std::string &string, const sf::Vector2f &position);

};


#endif //WIDGETS_BUTTON_H
