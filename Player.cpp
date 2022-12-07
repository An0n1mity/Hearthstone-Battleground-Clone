#include "Player.h"

std::string Card::getOwnerName()
{
    return m_owner->getName();
}

std::ostream &operator<<(std::ostream &os, Player &player)
{
    os << "Player name: " << player.m_name << '\n';
    os << "Player golds: " << player.m_golds << '\n';

    os << "Player hero: " << '\n';
    os << "Player deck: " << '\n';
    for (auto &card : player.m_on_hand)
    {
        card->print();
    }
    return os;
}

void Player::addCardToHand(std::unique_ptr<Card> card)
{
    // Set the owner of the card
    card->setOwner(this);
    // Add the card to the hand
    m_on_hand.push_back(std::move(card));
}

void Player::moveCardFromHandToBoard(int index)
{
    // Sanity check
    if (index < 0 || index >= m_on_hand.size() || m_on_hand.empty())
        return;

    // Add the card to the board
    m_board->addCard(std::move(m_on_hand[index]));
}