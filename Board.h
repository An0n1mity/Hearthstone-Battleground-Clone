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
    std::vector<std::unique_ptr<Card>> m_cards;

public:
    Board(){};
    ~Board()
    {
        std::cout << "Board destructor" << std::endl;
    };
    // Get a view of the cards of a certain player
    std::vector<Card *> getPlayerCardsView(Player *player);

    // Get Cards of the board
    std::vector<Card *> getCardsView();

    // Get the cards of a certain type on the board and own by a certain player
    /*template <typename T>
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
    }*/

    // Add a card to the board
    void addCard(std::unique_ptr<Card> &card)
    {
        // Show the reference count of the card
        m_cards.push_back(std::move(card));
    }
    // Print the cards on the board
    void printCards()
    {
        std ::cout << "Cards on the board: " << '\n';
        for (auto &card : m_cards)
        {
            card->print();
        }
    }

    //remove a card from the board
    void removeCard(int index)
    {
        m_cards.erase(m_cards.begin() + index);
    }

    // Pop a card from the board
    std::unique_ptr<Card> popCard(int index)
    {
        Card *ptr = m_cards[index].get();
        std::unique_ptr<Card> card = std::unique_ptr<Card>(ptr);
        m_cards.erase(m_cards.begin() + index);
        return card;
    }
};

#endif