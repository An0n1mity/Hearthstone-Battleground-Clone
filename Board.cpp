#include "Board.h"
#include "Minions.h"
#include <typeinfo>
#include "Player.h"

std::vector<std::reference_wrapper<Card>> Board::getPlayerCardsView(Player &player)
{
    std::vector<std::reference_wrapper<Card>> player_cards;
    for (auto &card : m_cards)
    {
        // Lock the weak pointer
        std::experimental::observer_ptr<Player> player_ptr_ = card->getOwner();
        if (player_ptr_.get() == &player)
        {
            player_cards.push_back(std::ref(*card));
        }
    }
    return player_cards;
}

std::vector<std::reference_wrapper<Card>> Board::getCardsView()
{
    std::vector<std::reference_wrapper<Card>> cards;
    for (auto &card : m_cards)
    {
        cards.push_back(std::ref(*card));
    }
    return cards;
}

