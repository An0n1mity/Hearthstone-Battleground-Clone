#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class CardGraphic;
class Card;

class BoardGraphic
{
private:
    sf::Texture m_board_texture;
    sf::Sprite m_board_sprite;

    // Rectangles for slots
    sf::RectangleShape m_shop_slot = sf::RectangleShape(sf::Vector2f(400, 80));
    sf::Vector2f m_shop_slot_pos = sf::Vector2f(300, 150);

    // Texture of cards in shop slot
    std::vector<CardGraphic> m_shop_slot_card_graphics;

public:
    BoardGraphic(){};
    ~BoardGraphic(){};

    void draw(sf::RenderWindow &window);
    void loadTexture();
    // Return texture dimensions
    sf::Vector2u getTextureSize() { return m_board_texture.getSize(); }
    // Player choices card texture
    void loadShopSlotTexture(std::vector<Card &> cards);
    // Add cards to shop slot
    void addCardGraphicToShopSlot(std::vector<CardGraphic> &card_graphics);
    // Draw shop slot cards
    void drawShopSlotCards(sf::RenderWindow &window);
};