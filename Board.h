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
    // Get a view of the cards of an other player
    std::vector<std::reference_wrapper<Card>> getOtherPlayerCardsView(const Player &player) const;
    // Get a view of the cards with taunt effect of a certain player
    std::vector<std::reference_wrapper<Card>> getPlayerCardsViewWithTaunt(const Player &player) const;
    // Get a view of the cards with taunt effect of an other player
    std::vector<std::reference_wrapper<Card>> getOtherPlayerCardsViewWithTaunt(const Player &player) const;
    // Get the number of cards of the player 
    int getNumberOfCards(const Player &player) const;

    // Get Cards of the board
    std::vector<std::reference_wrapper<Card>> getCardsView();

    // Get the cards of a certain type on the board and own by a certain player

    void addCardLeft(std::unique_ptr<Card> &card);
    void addCardRight(std::unique_ptr<Card> &card);
    void destroyCard(Card &card);
    void destroyCards();
    int getCardIndex(Card &card) const;
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
