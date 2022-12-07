#include "Player.h"

std::ostream &operator<<(std::ostream &os, Player &player)
{
    os << "Player name: " << player.m_name << '\n';
    os << "Player golds: " << player.m_golds << '\n';

    os << "Player hero: " << '\n';
    os << "Player deck: " << '\n';
    for (auto &card : player.m_hand)
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

void Player::addCardToHand(std::unique_ptr<Card> card)
{
    // Set the owner of the card
    card->setOwner(this);
    m_hand.push_back(std::move(card));
}

void Player::moveCardFromHandToBoard(int index)
{
    // Sanity check
    if (index < 0 || index >= m_hand.size() || m_hand.empty())
        return;

    m_board->addCard(std::move(m_hand[index]));
}

void Player::linkBoard(std::shared_ptr<Board> board)
{
    m_board = board;
}