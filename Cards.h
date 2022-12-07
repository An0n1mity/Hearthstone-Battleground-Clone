#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Effects.h"

class Player;

class Card
{
protected:
    // The card player owner
    Player *m_owner;
    // The card's gold cost
    const unsigned int m_gold_cost;
    // The card's effects
    std::vector<std::unique_ptr<Effect>> m_effects;

    virtual void printType() const = 0;
    virtual void printName() const = 0;

public:
    Card(unsigned int gold_cost, std::vector<std::unique_ptr<Effect>> effects = {}) : m_gold_cost(gold_cost), m_effects(std::move(effects)) {}
    virtual ~Card() {}
    unsigned int getManaCost() { return m_gold_cost; }
    std::string getOwnerName();
    Player *getOwner() { return m_owner; }
    void print()
    {
        std::cout << "{Card type: ";
        printType();
        std::cout << "; Card name: ";
        printName();
        std::cout << "; Card cost: " << m_gold_cost;
        std::cout << "; Card owner: " << getOwnerName() << "}\n";
    }

    // Apply the effects of the card
    void applyEffects() const
    {
        for (const auto &effect : m_effects)
        {
            effect->activate();
        }
    }

    // Set the owner of the card
    void setOwner(Player *owner) { m_owner = owner; }
};

#endif