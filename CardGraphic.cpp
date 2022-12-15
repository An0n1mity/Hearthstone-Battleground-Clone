#include "CardGraphic.h"

sf::Texture CardGraphic::loadTexture(Card &card)
{
    sf::Texture texture;
    // Card name
    std::string card_name = card.getName();
    // Load the texture
    texture.loadFromFile("../assets/" + card_name + ".png");
    return texture;
}
