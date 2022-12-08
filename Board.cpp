#include "Board.h"
#include "Minions.h"
#include <typeinfo>

std::vector<std::shared_ptr<Card>> Board::getPlayerCards(Player *player)
{
    std::vector<std::shared_ptr<Card>> player_cards;
    for (auto card : m_cards)
    {
        if (card->getOwner() == player)
        {
            player_cards.push_back(card);
        }
    }
    return player_cards;
}
