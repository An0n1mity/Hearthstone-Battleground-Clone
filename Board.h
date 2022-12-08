#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include <vector>

#include "Cards.h"
#include "Minions.h"

class Player;

class Board
{
private:
    // A vector of cards on the board
    std::vector<std::shared_ptr<Card>> m_cards;

public:
    Board(){};
    ~Board()
    {
        std::cout << "Board destructor" << std::endl;
        // destroy all the cards on the board
        for (auto card : m_cards)
        {
            card.reset();
        }
    };
    // Get the cards own by a certain player on the board
    std::vector<std::shared_ptr<Card>> getPlayerCards(Player *player);

    // Get the cards of a certain type on the board and own by a certain player
    template <typename T>
    std::vector<std::shared_ptr<Card>> getPlayerCardsOfSameTypeAs(Player *player, Card *card_)
    {
        std::vector<std::shared_ptr<Card>> player_cards;
        for (auto card : m_cards)
        {
            // synamic cast to a minion
            Minion *minion_ptr = dynamic_cast<Minion *>(card.get());
            // dynamic cast T to a minion
            Minion *minion_ptr2 = dynamic_cast<Minion *>(card_);
            // Debug the type of the minion
            if (card->getOwner() == player && minion_ptr->getType() == minion_ptr2->getType())
            {
                player_cards.push_back(card);
            }
        }
        return player_cards;
    }
    // Add a card to the board
    void addCard(std::unique_ptr<Card> card)
    {
        // Show the reference count of the card
        m_cards.push_back(std::move(card));
    }
    // Print the cards on the board
    void printCards()
    {
        std ::cout << "Cards on the board: " << '\n';
        for (auto card : m_cards)
        {
            card->print();
        }
    }

    // Debugging reference count of the cards
    void printCardsRefCount()
    {
        std ::cout << "Cards on the board: " << '\n';
        for (auto card : m_cards)
        {
            std::cout << "Reference count of the card: " << card.use_count() << std::endl;
        }
    }
};

#endif