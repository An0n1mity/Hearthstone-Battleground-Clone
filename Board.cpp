#include "Board.h"
#include "Minions.h"
#include <typeinfo>
#include "Player.h"

std::vector<std::reference_wrapper<Card>> Board::getPlayerCardsView(const Player &player) const
{
    std::vector<std::reference_wrapper<Card>> player_cards;
    // Check if the card is owned by the player id
    if (player.getId() == 1)
    {
        for (auto &card : m_player1_cards)
        {
            player_cards.push_back(std::ref(*card));
        }
    }
    else if (player.getId() == 2)
    {
        for (auto &card : m_player2_cards)
        {
            player_cards.push_back(std::ref(*card));
        }
    }

    return player_cards;
}

std::vector<std::reference_wrapper<Card>> Board::getOtherPlayerCardsView(const Player &player) const
{
    std::vector<std::reference_wrapper<Card>> player_cards;
    // Check if the card is owned by the player id
    if (player.getId() == 1)
    {
        for (auto &card : m_player2_cards)
        {
            player_cards.push_back(std::ref(*card));
        }
    }
    else if (player.getId() == 2)
    {
        for (auto &card : m_player1_cards)
        {
            player_cards.push_back(std::ref(*card));
        }
    }

    return player_cards;
}

std::vector<std::reference_wrapper<Card>> Board::getPlayerCardsViewWithTaunt(const Player &player) const
{
    std::vector<std::reference_wrapper<Card>> player_cards;
    // Check if the card is owned by the player id
    if (player.getId() == 1)
    {
        for (auto &card : m_player1_cards)
        {
            // Dynamic cast
            Minion *minion_ptr = dynamic_cast<Minion *>(card.get());
            if (minion_ptr->hasEffect("TAUNT"))
            {
                player_cards.push_back(std::ref(*card));
            }
        }
    }
    else if (player.getId() == 2)
    {
        for (auto &card : m_player2_cards)
        {
            // Dynamic cast
            Minion *minion_ptr = dynamic_cast<Minion *>(card.get());
            if (minion_ptr->hasEffect("TAUNT"))
            {
                player_cards.push_back(std::ref(*card));
            }
        }
    }

    return player_cards;
}

std::vector<std::reference_wrapper<Card>> Board::getOtherPlayerCardsViewWithTaunt(const Player &player) const
{
    std::vector<std::reference_wrapper<Card>> player_cards;
    // Check if the card is owned by the player id
    if (player.getId() == 1)
    {
        for (auto &card : m_player2_cards)
        {
            // Dynamic cast
            Minion *minion_ptr = dynamic_cast<Minion *>(card.get());
            if (minion_ptr->hasEffect("TAUNT"))
            {
                player_cards.push_back(std::ref(*card));
            }
        }
    }
    else if (player.getId() == 2)
    {
        for (auto &card : m_player1_cards)
        {
            // Dynamic cast
            Minion *minion_ptr = dynamic_cast<Minion *>(card.get());
            if (minion_ptr->hasEffect("TAUNT"))
            {
                player_cards.push_back(std::ref(*card));
            }
        }
    }

    return player_cards;
}

std::vector<std::reference_wrapper<Card>> Board::getCardsView()
{
    std::vector<std::reference_wrapper<Card>> cards;
    for (auto &card : m_player1_cards)
    {
        cards.push_back(std::ref(*card));
    }
    for (auto &card : m_player2_cards)
    {
        cards.push_back(std::ref(*card));
    }
    return cards;
}

void Board::addCardLeft(std::unique_ptr<Card> &card)
{
    std::experimental::observer_ptr<Player> player_ptr = card->getOwner();
    // If the player id is 1
    if (player_ptr->getId() == 1)
    {
        // Add the card to the left of the board
        m_player1_cards.insert(m_player1_cards.begin(), std::move(card));
    }
    // If the player id is 2
    else if (player_ptr->getId() == 2)
    {
        // Add the card to the left of the board
        m_player2_cards.insert(m_player2_cards.begin(), std::move(card));
    }
}

void Board::addCardRight(std::unique_ptr<Card> &card)
{
    // Check the player id of the card
    std::experimental::observer_ptr<Player> player_ptr = card->getOwner();
    // If the player id is 1
    if (player_ptr->getId() == 1)
    {
        // Add the card to the right of the board
        m_player1_cards.push_back(std::move(card));
    }
    // If the player id is 2
    else if (player_ptr->getId() == 2)
    {
        // Add the card to the right of the board
        m_player2_cards.push_back(std::move(card));
    }
}

void Board::destroyCards()
{
    for (size_t i = 0; i < m_player1_cards.size(); i++)
    {
        // Dynamic cast to minion
        Minion *minion = dynamic_cast<Minion *>(m_player1_cards[i].get());
        if (minion->getHealth() <= 0)
        {
            m_destroyed_cards.push_back(std::move(m_player1_cards[i]));
            m_player1_cards.erase(m_player1_cards.begin() + i);
            m_destroyed_cards[m_destroyed_cards.size()-1]->applyEffects(Effect::ON_DEATH);
        }
    }
    for (size_t i = 0; i < m_player2_cards.size(); i++)
    {
        // Dynamic cast to minion
        Minion *minion = dynamic_cast<Minion *>(m_player2_cards[i].get());
        if (minion->getHealth() <= 0)
        {
            m_destroyed_cards.push_back(std::move(m_player2_cards[i]));
            m_player2_cards.erase(m_player2_cards.begin() + i);
            m_destroyed_cards[m_destroyed_cards.size()-1]->applyEffects(Effect::ON_DEATH);
        }
    }
}
std::unique_ptr<Card> Board::popCard(int index, Player &player)
{
    std::unique_ptr<Card> card;
    if (player.getId() == 0)
    {
        card = std::move(m_player1_cards[index]);
        m_player1_cards.erase(m_player1_cards.begin() + index);
    }
    else if (player.getId() == 1)
    {
        card = std::move(m_player2_cards[index]);
        m_player2_cards.erase(m_player2_cards.begin() + index);
    }
    return card;
}

int Board::getNumberOfCards(const Player &player) const
{
	if (player.getId() == 0)
	{
		return m_player1_cards.size();
	}
	else if (player.getId() == 1)
	{
		return m_player2_cards.size();
	}
	return 0;
}

int Board::getCardIndex(Card &card) const
{
    // Check the player id of the card
    std::experimental::observer_ptr<Player> player_ptr = card.getOwner();
    // If the player id is 1
    if (player_ptr->getId() == 1)
    {
        auto it = std::find_if(m_player1_cards.begin(), m_player1_cards.end(), [&card](const std::unique_ptr<Card> &card_)
                               { return card_.get() == &card; });
        // Get index
        int index = std::distance(m_player1_cards.begin(), it);
        return index;
    }
    // If the player id is 2
    else if (player_ptr->getId() == 2)
    {
        auto it = std::find_if(m_player2_cards.begin(), m_player2_cards.end(), [&card](const std::unique_ptr<Card> &card_)
                               { return card_.get() == &card; });
        // Get index
        int index = std::distance(m_player2_cards.begin(), it);
        return index;
    }
    return -1;
}
