#ifndef MINIONSCARDS_H
#define MINIONSCARDS_H

#include "MinionsTribes.h"
#include "Board.h"
class AlleyCat : public Beast
{

public:
    static void Summon1_1Cat(Card *card)
    {
        Minion::summonMinion<AlleyCat>(card->getBoard(), card);
    }

    AlleyCat() : Beast(1, 1, 1)
    {
        // Create a battle cry effect that have a pointer to the function Summon1_1Cat
        Effect *battlecry = new Battlecry(Summon1_1Cat, this);
        // Add the effect to the vector of effects
        m_effects.push_back(std::unique_ptr<Effect>(battlecry));
    }
    virtual ~AlleyCat() {}
    virtual void printName() const override { std::cout << "AlleyCat"; }
    virtual std::string getName() const override { return "AlleyCat"; }
};

class DeckSwabbie : public Pirate
{
public:
    DeckSwabbie() : Pirate(1, 2, 2) {}
    virtual ~DeckSwabbie() {}
    virtual void printName() const override { std::cout << "DeckSwabbie"; }
    virtual std::string getName() const override { return "DeckSwabbie"; }
    // Clone the card
};

#endif