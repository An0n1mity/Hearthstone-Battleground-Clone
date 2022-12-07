#include "Player.h"

std::ostream &operator<<(std::ostream &os, Player &player)
{
    os << "Player name: " << player.m_name << '\n';
    os << "Player golds: " << player.m_golds << '\n';
    os << "Player level: " << player.m_level << '\n'; 
    /*os << "Player hero: ";
    player.m_hero->printName();*/
    os << "\nPlayer deck: " << '\n';
    for (auto &card : player.m_in_hand)
    {
        os << "- ";
        card->printName();
        os << '\n';
    }
    os << "\nPlayer board: " << '\n';
    for (auto &card : player.m_on_board)
    {
        os << "- ";
        card->printName();
        os << '\n';
    }
    return os;
}

void Player::addHero(std::unique_ptr<Hero> hero)
{
    m_hero = std::move(hero);
}

void Player::addCardToHand(std::unique_ptr<Card> card)
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