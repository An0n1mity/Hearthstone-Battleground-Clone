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
    // The card's owner
    Player *m_owner;
    const unsigned int m_gold_cost;
    // The card's effects
    std::vector<std::unique_ptr<Effect>> m_effects;

public:
    virtual void printType() const = 0;
    virtual void printName() const = 0;
    Card(unsigned int gold_cost, std::vector<std::unique_ptr<Effect>> effects = {}) : m_gold_cost(gold_cost), m_effects(std::move(effects)) {}
    virtual ~Card() {}
    unsigned int getManaCost() const { return m_gold_cost; }
    void print() const
    {
        std::cout << "{Card type: ";
        printType();
        std::cout << "; Card name: ";
        printName();
        std::cout << "; Card cost: " << m_gold_cost << "}\n";
    }

    // Apply the effects of the card
    void applyEffects() const
    {
        for (const auto &effect : m_effects)
        {
            effect->activate();
        }
    }

    Player *getOwner() { return m_owner; }
    void setOwner(Player *owner) { m_owner = owner; }
    virtual int getRang() const = 0;
};

#endif