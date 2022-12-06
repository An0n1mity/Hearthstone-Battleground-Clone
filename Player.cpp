#include "Player.h"

std::ostream &operator<<(std::ostream &os, Player &player)
{
    os << "Player name: " << player.m_name << '\n';
    os << "Player golds: " << player.m_golds << '\n';

    os << "Player hero: " << '\n';
    os << "Player deck: " << '\n';
    for (auto &card : player.m_deck)
    {
        card->print();
    }
    os << "Player board: " << '\n';
    for (auto &card : player.m_on_board)
    {
        card->print();
    }
    return os;
}

void Player::addCardToDeck(std::unique_ptr<Card> card)
{
    m_deck.push_back(std::move(card));
}

void Player::moveCardFromDeckToBoard(int index)
{
    // Sanity check
    if (index < 0 || index >= m_deck.size() || m_deck.empty())
        return;

    m_on_board.push_back(std::move(m_deck[index]));
    m_deck.erase(m_deck.begin() + index);
}