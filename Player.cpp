#include "Player.h"

std::ostream &operator<<(std::ostream &os, Player &player)
{
    os << "Player name: " << player.m_name << '\n';
    os << "Player golds: " << player.m_golds << '\n';

    os << "Player hero: " << '\n';
    if (player.m_hand.size() > 0){
        os << "Player deck: " << '\n';
        for (auto &card : player.m_hand)
        {
            card->print();
        }
    }
    std::shared_ptr<Board> board = player.m_board.lock();
    std::vector<std::shared_ptr<Card>> boardCard;
    for(auto &card : board->getPlayerCards(&player))
    {   
        boardCard.push_back(card.lock());
    }
    if (boardCard.size() > 0)
    {
        os << "\nPlayer board: " << '\n';
        for (auto &card : boardCard)
        {
            os << "- ";
            card->printName();
            os << '\n';
        }
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
    m_hand.erase(m_hand.begin() + index);
}

void Player::linkBoard(std::weak_ptr<Board> board)
{
    m_board = board;
}

// Give a card to the shop
void Player::sellCardFromHand(int index, Shop *shop)
{
    // Sanity check
    if (index < 0 || index >= m_hand.size() || m_hand.empty())
        return;

    // Move the card from the hand to the shop
    std::unique_ptr<Card> card_to_move = std::move(m_hand[index]);
    shop->sellCard(card_to_move, this);
    // Remove the card from the hand
    m_hand.erase(m_hand.begin() + index);
}

void Player::giveCardFromBoard(int index, Shop *shop, Player *player)
{
    std::shared_ptr<Board> board = m_board.lock();
    std::vector<std::shared_ptr<Card>> boardCard;
    for(auto &card : board->getCards())
    {   
        boardCard.push_back(card.lock());
    }
    // Sanity check
    if (index < 0 || index >= boardCard.size() || boardCard.empty())
        return;

    int counter = -1;
    for(int i = 0; i < boardCard.size(); i++)
    {
        if (boardCard[i]->getOwner() == player)
        {
            counter++;
        }
        if (counter == index)
        {
            counter = i;
            break;
        }
    }
    // Get raw pointer to the card
    Card *card = boardCard[counter].get();
    // Remove the card from the board
    board->removeCard(counter);
    // Give the card to the shop converts the raw pointer to a unique pointer
    std::unique_ptr<Card> card_ptr(card);
    shop->sellCard(card_ptr, card->getOwner());
}