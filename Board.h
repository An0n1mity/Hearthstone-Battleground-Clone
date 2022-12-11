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
    std::vector<std::unique_ptr<Card>> m_player1_cards;
    std::vector<std::unique_ptr<Card>> m_player2_cards;

    // remove a card from the board
    void removeCard(int index)
    {
        m_cards.erase(m_cards.begin() + index);
    }

public:
    Board(){};
    ~Board()
    {
        std::cout << "Board destructor" << std::endl;
    };
    // Get a view of the cards of a certain player
    std::vector<std::reference_wrapper<Card>> getPlayerCardsView(Player &player);

    // Get Cards of the board
    std::vector<std::reference_wrapper<Card>> getCardsView();

    // Get the cards of a certain type on the board and own by a certain player
    template <typename T>
    std::vector<std::reference_wrapper<Card>> getPlayerCardsOfSameTypeAsView(std::weak_ptr<Player> player, Card *card_)
    {
        // Lock the weak pointer
        std::shared_ptr<Player> player_ptr = player.lock();
        std::vector<std::reference_wrapper<Card>> player_cards;
        for (auto card : m_cards)
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
        return player_cards;
    }

    // Add a card to the board
    void addCard(std::unique_ptr<Card> &card)
    {
        // Show the reference count of the card
        m_cards.push_back(std::move(card));
    }
    void addCardLeft(std::unique_ptr<Card> &card, Player *player)
    {
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
    // Pop a card from the board
    std::unique_ptr<Card> popCard(int index)
    {
        Card *ptr = m_cards[index].get();
        std::unique_ptr<Card> card = std::unique_ptr<Card>(ptr);
        removeCard(index);
        return card;
    }
};

#endif