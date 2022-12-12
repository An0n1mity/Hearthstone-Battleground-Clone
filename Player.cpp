#include "Player.h"

std::ostream &operator<<(std::ostream &os, Player &player)
{
    os << "Player id: " << player.m_id << '\n';
    os << "Player name: " << player.m_name << '\n';
    os << "Player golds: " << player.m_golds << '\n';

    os << "Player hero: " << '\n';
    if (player.m_hand.size() > 0)
    {
        os << "Player deck: " << '\n';
        for (auto &card : player.m_hand)
        {
            card->print();
        }
    }

    return os;
}

void Player::addCardToHand(std::unique_ptr<Card> &card)
{
    // Set the owner of the card
    // card->linkPlayer(std::ref(*this));
    m_hand.push_back(std::move(card));
}

void Player::moveCardFromHandToBoardLeft(int index)
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
    m_board->addCardLeft(card_to_move);
    m_hand.erase(m_hand.begin() + index);
}

void Player::linkBoard(std::experimental::observer_ptr<Board> board)
{
    m_board = board;
}

void Player::buyCardFromShop(std::vector<std::reference_wrapper<Card>> &cards, int index, Shop &shop)
{
    // Sanity check
    if (index < 0 || index >= cards.size() || cards.empty())
        return;

    // Move the card from the shop to the hand
    shop.buyCard(index, *this);
}

// Give a card to the shop
void Player::sellCardFromHand(int index, Shop &shop)
{
    // Sanity check
    if (index < 0 || index >= m_hand.size() || m_hand.empty())
        return;

    // Move the card from the hand to the shop
    std::unique_ptr<Card> card_to_move = std::move(m_hand[index]);
    shop.sellCard(card_to_move, this);
    // Remove the card from the hand
    m_hand.erase(m_hand.begin() + index);
}

void Player::giveCardFromBoard(int index, Shop &shop)
{
    // Sanity check
    if (index < 0 || index >= m_hand.size() || m_hand.empty())
        return;

    std::experimental::observer_ptr<Board> board = m_board;
    // Move the card from the board to the shop
    std::unique_ptr<Card> card_to_move = board->popCard(index, *this);
    shop.sellCard(card_to_move, this);
}