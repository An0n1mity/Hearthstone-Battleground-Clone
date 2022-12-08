#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include <vector>

#include "Cards.h"

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