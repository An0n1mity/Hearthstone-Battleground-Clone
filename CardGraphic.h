#include <SFML/Graphics.hpp>
#include "Cards.h"

class CardGraphic
{

    static sf::Texture loadTexture(Card &card);

private:
    // Card rectangle
    sf::RectangleShape m_card_rect;
    // Card texture
    sf::Texture m_card_texture;
    sf::Sprite m_card_sprite;

public:
    CardGraphic(Card &card)
    {
        // Set the card rectangle
        m_card_rect.setSize(sf::Vector2f(100, 80));
        m_card_rect.setFillColor(sf::Color::Red);
        // Load the card texture
        m_card_texture = loadTexture(card);
        m_card_sprite.setTexture(m_card_texture);
        // Set the card sprite position
        m_card_sprite.setPosition(m_card_rect.getPosition());
        // set the card sprite scale to fit the rectangle
        m_card_sprite.setScale(m_card_rect.getSize().x / m_card_sprite.getGlobalBounds().width,
                               m_card_rect.getSize().y / m_card_sprite.getGlobalBounds().height);
        }
    ~CardGraphic(){};

    // Return the card rectangle
    sf::RectangleShape getCardRect() { return m_card_rect; }
    // Set the card rectangle position
    void setCardRectPosition(sf::Vector2f position)
    {
        m_card_rect.setPosition(position);
        m_card_sprite.setPosition(position);
    }

    void draw(sf::RenderWindow &window)
    {
        // Draw the card rectangle
        window.draw(m_card_rect);
        // Draw the card sprite
        window.draw(m_card_sprite);
    }
};
