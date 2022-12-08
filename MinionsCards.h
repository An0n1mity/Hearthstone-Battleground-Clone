#ifndef MINIONSCARDS_H
#define MINIONSCARDS_H

#include "MinionsTribes.h"
#include "Board.h"
class AlleyCat : public Beast
{

public:
    static void Summon1_1Cat(Card *card)
    {
        std::cout << "Summoning a 1/1 Cat" << std::endl;
        // Get the card board
        std::weak_ptr<Board> board = card->getBoard();
        // Create a new card
        std::unique_ptr<Card> newCard = std::make_unique<AlleyCat>();
        // Assign the card to the player
        newCard->setOwner(card->getOwner());
        // Add the card to the board
        // Convert the board to a shared pointer
        std::shared_ptr<Board> board_ptr = board.lock();
        board_ptr->addCard(std::move(newCard));
    }

    AlleyCat() : Beast(1, 1)
    {
        // Create a battle cry effect that have a pointer to the function Summon1_1Cat
        Effect *battlecry = new Battlecry(Summon1_1Cat, this);
        // Add the effect to the vector of effects
        m_effects.push_back(std::unique_ptr<Effect>(battlecry));
    }
    virtual ~AlleyCat() {}
    virtual void printName() const override { std::cout << "AlleyCat"; }
};

class DeckSwabbie : public Pirate
{
public:
    DeckSwabbie() : Pirate(2, 2) {}
    virtual ~DeckSwabbie() {}
    virtual void printName() const override { std::cout << "DeckSwabbie"; }
};

#endif