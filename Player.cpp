#include "Player.h"
#define PLAYER_DEBUG 1

std::ostream &operator<<(std::ostream &os, Player &player)
{
    os << "Player id: " << player.m_id << '\n';
    os << "Player name: " << player.m_name << '\n';
    os << "Player golds: " << player.m_golds << '\n';

    os << "Player hero: " << '\n';
    player.printChoices();
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
#if PLAYER_DEBUG
    std::cout << "[PLAYER DEBUG]: Called from " << __FILE__ << " line " << __LINE__ << " Player::moveCardFromHandToBoardLeft " << '\n';
#endif
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

void Player::addCardToChoices(Card &card)
{
    m_choices.push_back(card);
}

void Player::selectCardFromChoices(int index, Shop &shop)
{
#if PLAYER_DEBUG
    std::cout << "[PLAYER DEBUG]: Called from " << __FILE__ << " line " << __LINE__ << " Player::selectCardFromChoices " << '\n';
#endif
    // Sanity check
    if (index < 0 || index >= m_choices.size() || m_choices.empty())
        return;
    std::cout << "ID: " << m_choices[index].get().getId() << '\n';
    shop.giveCardToPlayer(*this, m_choices[index]);
    m_choices.erase(m_choices.begin() + index);
}

void Player::resetChoices()
{
	m_choices.clear();
}

void Player::printChoices() const
{
    std::cout << "Choices: " << '\n';
    for (auto card_ref : m_choices)
    {
        Card &card = card_ref.get();
        card.print();
    }
}

std::vector<std::reference_wrapper<Card>> Player::getHandView() const
{
	std::vector<std::reference_wrapper<Card>> hand_view;
	for (auto &card : m_hand)
	{
		hand_view.push_back(std::ref(*card));
	}
	return hand_view;
}

void Player::upgradeLevel()
{
    if(m_golds >= 5){
        m_golds -= 5;
        m_level++;
        for(auto &card : m_board->getPlayerCardsView(*this)){
            card.get().applyEffects(Effect::ON_UPGRADE);
        }
    }
    else{
        std::cout << "Not enough golds" << '\n';
    } 
}
