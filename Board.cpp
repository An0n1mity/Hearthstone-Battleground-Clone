#include "Board.h"
#include "Minions.h"
#include <typeinfo>

std::vector<Card *> Board::getPlayerCardsView(Player *player)
{
    std::vector<Card *> player_cards;
    // Move the cards to the player_cards vector
    for (auto &card : m_cards)
    {
        if (card->getOwner() == player)
        {
            player_cards.push_back(card.get());
        }
    }
    return player_cards;
}

std::vector<Card *> Board::getCardsView()
{
    std::vector<Card *> cards;
    for (auto &card : m_cards)
    {
        cards.push_back(card.get());
    }
    return cards;
}
