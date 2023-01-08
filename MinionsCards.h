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
	
	// Effect description 
	m_effect_description = "Battlecry: Summon a 1/1 Cat";
        // Create a battle cry effect that have a pointer to the function Summon1_1Cat
        Effect *battlecry = new Battlecry(Summon1_1Cat, this);
        // Add the effect to the vector of effects
        m_effects.push_back(std::unique_ptr<Effect>(battlecry));
    }
    virtual ~AlleyCat() {}
    virtual void printName() const override { std::cout << "AlleyCat"; }
    virtual const std::string getName() const override { return "AlleyCat"; }
};

class DeckSwabbie : public Pirate
{
public:
    DeckSwabbie() : Pirate(1, 2, 2) {
	// Effect description 
	m_effect_description = "Battlecry: Give your weapon +1 Attack";
    }
    virtual ~DeckSwabbie() {}
    virtual void printName() const override { std::cout << "DeckSwabbie"; }
    virtual const std::string getName() const override { return "DeckSwabbie"; }
};

class DozyWhelp : public Dragon
{
public:
    static void Gain1AttackPoint(Card *card)
    {
	Minion::buffAttackPoint(card, 1);
    }
    DozyWhelp() : Dragon(1, 3, 0)
    {
	Effect *taunt = new Taunt(Gain1AttackPoint, this);
	m_effect_description = "Taunt: Whenether attacked, gain +1 Attack";
	m_effects.push_back(std::unique_ptr<Effect>(taunt));
    }
    virtual ~DozyWhelp() {}
    virtual void printName() const override { std::cout << "DozyWhelp"; }
    virtual const std::string getName() const override { return "DozyWhelp"; }
};

#endif
