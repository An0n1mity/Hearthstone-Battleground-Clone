#include "Player.h"

std::ostream &operator<<(std::ostream &os, Player &player)
{
    os << "Player name: " << player.m_name << '\n';
    os << "Player golds: " << player.m_golds << '\n';
    os << "Player level: " << player.m_level << '\n'; 
    /*os << "Player hero: ";
    player.m_hero->printName();*/
    if (player.m_in_hand.size() > 0)
    {
        os << "\nPlayer deck: " << '\n';
        for (auto &card : player.m_in_hand)
        {
            os << "- ";
            card->printName();
            os << '\n';
        }
    }
    std::unique_ptr<Player> p = std::unique_ptr<Player>(&player);
    if (player.getBoard()->getPlayerCards(p.get()).size() > 0)
    {
        os << "\nPlayer board: " << '\n';
        for (auto &card : player.getBoard()->getPlayerCards(p.get()))
        {
            os << "- ";
            card->printName();
            os << '\n';
        }
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

    m_board->addCard(std::move(m_in_hand[index]));
    m_in_hand.erase(m_in_hand.begin() + index);
}

void Player::giveCardFromHand(int index, Shop *shop)
{
    // Sanity check
    if (index < 0 || index >= m_in_hand.size() || m_in_hand.empty())
        return;

    // Give the card to the shop
    std::unique_ptr<Card> card = std::move(m_in_hand[index]);
    shop->sellCard(std::move(card), this);
}