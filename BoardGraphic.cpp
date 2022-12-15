#include "BoardGraphic.h"
#include "CardGraphic.h"

void BoardGraphic::draw(sf::RenderWindow &window)
{
    // Draw the board background
    window.draw(m_board_sprite);
    // Draw the shop slot outline
    m_shop_slot.setPosition(m_shop_slot_pos);
    window.draw(m_shop_slot);

    // Draw the cards in the shop slot
    drawShopSlotCards(window);
}

void BoardGraphic::loadTexture()
{
    if (!m_board_texture.loadFromFile("../assets/Default_1_Texture_Details.png"))
    {
        std::cout << "Error loading board texture" << std::endl;
    }
    m_board_sprite.setTexture(m_board_texture);
    // Set rectangle transparency
    m_shop_slot.setFillColor(sf::Color(0, 0, 0, 0));
    m_shop_slot.setOutlineColor(sf::Color::Red);
    m_shop_slot.setOutlineThickness(5);
}

void BoardGraphic::addCardGraphicToShopSlot(std::vector<CardGraphic> &card_graphics)
{
    // Get the size
    size_t size = card_graphics.size();
    // Get the width of the card
    float card_width = card_graphics[0].getCardRect().getSize().x;
    // calculate the lenght of the cards rectangle
    float cards_rect_length = card_width * size;
    // Center the cards rectangle
    float start_x = m_shop_slot_pos.x + (m_shop_slot.getSize().x / 2.f) - (cards_rect_length / 2.f);

    size_t idx = 0;
    for (auto &card_graphic : card_graphics)
    {
        // new card graphic position
        sf::Vector2f new_position = sf::Vector2f(start_x + (card_width * idx), m_shop_slot_pos.y);
        // Set the card graphic position
        card_graphic.setCardRectPosition(new_position);
        // Print the card graphic position
        std::cout << "Card graphic position: " << card_graphic.getCardRect().getPosition().x << ", " << card_graphic.getCardRect().getPosition().y << std::endl;
        m_shop_slot_card_graphics.push_back(card_graphic);
        idx++;
    }
}

void BoardGraphic::drawShopSlotCards(sf::RenderWindow &window)
{
    for (auto &card_graphic : m_shop_slot_card_graphics)
    {
        card_graphic.draw(window);
    }
}