#include "Graphic.h"
#include "CardGraphic.h"

std::vector<CardGraphic> loadTextureFromCards(std::vector<Card> &cards)
{
    std::vector<CardGraphic> card_graphics;
    for (auto &card : cards)
    {
        card_graphics.push_back(CardGraphic(card));
    }
    return card_graphics;
}