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

    return os;
}

void Player::addCardToHand(std::unique_ptr<Card> &card)
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

    // Move the card from the hand to the board
    std::unique_ptr<Card> card_to_move = std::move(m_hand[index]);
    // Link the card to the board
    card_to_move->linkBoard(m_board);
    // Apply the effect of the card
    card_to_move->applyEffects(Effect::ON_HAND);
    // Aquire lock on the board
    std::shared_ptr<Board> board = m_board.lock();
    board->addCard(card_to_move);
}

void Player::linkBoard(std::weak_ptr<Board> board)
{
    m_board = board;
}