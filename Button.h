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

    sf::Sprite* m_sprite = new sf::Sprite();

    sf::Text* m_text = new sf::Text();

    sf::Vector2f m_position;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void (*func)(void*) = nullptr;

    void* args = nullptr;
protected:
    void resizeButton();
public:
    Button(const std::string &string, const sf::Vector2f &position);

    bool contains(sf::Vector2f position);

    bool clicked(sf::Event& event);

    void setFunction(void (*function)(void *), void *args);
};

void test(void *v = 0);
#endif //WIDGETS_BUTTON_H
