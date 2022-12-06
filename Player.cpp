#include "Player.h"

std::ostream &operator<<(std::ostream &os, Player &player)
{
    os << "Player name: " << player.m_name << '\n';
    os << "Player golds: " << player.m_golds << '\n';

    os << "Player hero: " << '\n';
    os << "Player deck: " << '\n';
    for (auto &card : player.m_in_hand)
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

void Player::addHero(std::unique_ptr<Hero> hero)
{
    m_hero = std::move(hero);
}

void Player::addCardToDeck(std::unique_ptr<Card> card)
{
    m_in_hand.push_back(std::move(card));
}

void Player::moveCardFromDeckToBoard(int index)
{
    // Sanity check
    if (index < 0 || index >= m_in_hand.size() || m_in_hand.empty())
        return;

    m_on_board.push_back(std::move(m_in_hand[index]));
    m_in_hand.erase(m_in_hand.begin() + index);
}