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
    std::vector<std::unique_ptr<Card>> m_player1_cards;
    std::vector<std::unique_ptr<Card>> m_player2_cards;
    // Vector of cards that have been destroyed 
    std::vector<std::unique_ptr<Card>> m_destroyed_cards;

public:
    Board(){};
    ~Board()
    {
    };
    // Get a view of the cards of a certain player
    std::vector<std::reference_wrapper<Card>> getPlayerCardsView(const Player &player) const;
    // Get the number of cards of the player 
    int getNumberOfCards(const Player &player) const;

    // Get Cards of the board
    std::vector<std::reference_wrapper<Card>> getCardsView();

    // Get the cards of a certain type on the board and own by a certain player
    template <typename T>
    std::vector<std::reference_wrapper<Card>> getPlayerCardsOfSameTypeAsView(std::experimental::observer_ptr<Player> player, Card *card_)
    {
        /*
        // Lock the weak pointer
        std::vector<std::reference_wrapper<Card>> player_cards;
        std::vector<std::reference_wrapper<Card>> cards = getPlayerCardsView(*player.get());

        for (auto card : cards)
        {
            // synamic cast to a minion
            Minion *minion_ptr = dynamic_cast<Minion *>(card.get());
            // dynamic cast T to a minion
            Minion *minion_ptr2 = dynamic_cast<Minion *>(card_);
            // Lock the weak pointer
            std::experimental::observer_ptr<Player> player_ptr_ = card->getOwner();
            // Debug the type of the minion
            if (player_ptr->get() == player_ptr->get() && minion_ptr->getType() == minion_ptr2->getType())
            {
                player_cards.push_back(std::ref(*card));
            }
        }
        return player_cards;*/
    }

    void addCardLeft(std::unique_ptr<Card> &card);
    void addCardRight(std::unique_ptr<Card> &card);
    void destroyCard(Card &card);
    void destroyCards();
    std::unique_ptr<Card> popCard(int index, Player &player);

    // Print the cards on the board
    void printCards()
    {
        std ::cout << "Cards on the board: " << '\n';
        for (auto &card : m_player1_cards)
        {
            card->print();
        }
        for (auto &card : m_player2_cards)
        {
            card->print();
        }
    }
};

#endif
