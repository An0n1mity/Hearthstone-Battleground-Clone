#include "../BoardGraphic.h"
#include "../CardGraphic.h"
#include "../MinionsCards.h"
#include "../Graphic.h"

#include <SFML/Window.hpp>

int main(int argc, char const *argv[])
{
    // Create a alleycat card
    std::unique_ptr<Card> alleycat = std::unique_ptr<Card>(new AlleyCat());
    std::unique_ptr<Card> alleycat2 = std::unique_ptr<Card>(new AlleyCat());
    std::unique_ptr<Card> alleycat3 = std::unique_ptr<Card>(new AlleyCat());
    // Create a card graphic
    CardGraphic card_graphic = CardGraphic(std::ref(*alleycat));
    CardGraphic card_graphic2 = CardGraphic(std::ref(*alleycat2));
    CardGraphic card_graphic3 = CardGraphic(std::ref(*alleycat3));
    // Create a vector of card graphic
    std::vector<CardGraphic> card_graphics;
    card_graphics.push_back(card_graphic);
    card_graphics.push_back(card_graphic2);
    card_graphics.push_back(card_graphic3);
    // Create a board graphic
    BoardGraphic board = BoardGraphic();
    board.loadTexture();
    // Add the card graphic to the board graphic
    board.addCardGraphicToShopSlot(card_graphics);

    // Get the texture size
    sf::Vector2u texture_size = board.getTextureSize();
    sf::RenderWindow window(sf::VideoMode(texture_size.x, texture_size.y), "Board");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 0;
            }
        }

        window.clear();
        board.draw(window);
        window.display();
    }
}
