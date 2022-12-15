#include "Board.h"
#include "Minions.h"
#include <typeinfo>
#include "Player.h"

std::vector<std::reference_wrapper<Card>> Board::getPlayerCardsView(Player &player)
{
    std::vector<std::reference_wrapper<Card>> player_cards;
    // Check if the card is owned by the player id
    if (player.getId() == 0)
    {
        for (auto &card : m_player1_cards)
        {
            player_cards.push_back(std::ref(*card));
        }
    }
    else if (player.getId() == 1)
    {
        for (auto &card : m_player2_cards)
        {
            player_cards.push_back(std::ref(*card));
        }
    }

    return player_cards;
}

std::vector<std::reference_wrapper<Card>> Board::getCardsView()
{
    std::vector<std::reference_wrapper<Card>> cards;
    for (auto &card : m_player1_cards)
    {
        cards.push_back(std::ref(*card));
    }
    for (auto &card : m_player2_cards)
    {
        cards.push_back(std::ref(*card));
    }
    return cards;
}

void Board::addCardLeft(std::unique_ptr<Card> &card)
{
    std::experimental::observer_ptr<Player> player_ptr = card->getOwner();
    // If the player id is 1
    if (player_ptr->getId() == 0)
    {
        // Add the card to the left of the board
        m_player1_cards.insert(m_player1_cards.begin(), std::move(card));
    }
    // If the player id is 2
    else if (player_ptr->getId() == 1)
    {
        // Add the card to the left of the board
        m_player2_cards.insert(m_player2_cards.begin(), std::move(card));
    }
}

void Board::addCardRight(std::unique_ptr<Card> &card)
{
    // Check the player id of the card
    std::experimental::observer_ptr<Player> player_ptr = card->getOwner();
    // If the player id is 1
    if (player_ptr->getId() == 1)
    {
        // Add the card to the right of the board
        m_player1_cards.push_back(std::move(card));
    }
    // If the player id is 2
    else if (player_ptr->getId() == 2)
    {
        // Add the card to the right of the board
        m_player2_cards.push_back(std::move(card));
    }
}

std::unique_ptr<Card> Board::popCard(int index, Player &player)
{
    std::unique_ptr<Card> card;
    if (player.getId() == 0)
    {
        card = std::move(m_player1_cards[index]);
        m_player1_cards.erase(m_player1_cards.begin() + index);
    }
    else if (player.getId() == 1)
    {
        card = std::move(m_player2_cards[index]);
        m_player2_cards.erase(m_player2_cards.begin() + index);
    }
    return card;
}