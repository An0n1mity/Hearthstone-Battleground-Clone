#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Effects.h"

class Player;
class Board;

class Card
{

protected:
    // The card's owner
    Player *m_owner;
    // The card can be linked to a board
    std::weak_ptr<Board> m_board;
    const unsigned int m_gold_cost;
    // The card's effects
    std::vector<std::unique_ptr<Effect>> m_effects;
    virtual void printType() const = 0;
    virtual void printName() const = 0;

public:
    Card(unsigned int gold_cost, std::vector<std::unique_ptr<Effect>> effects = {}) : m_gold_cost(gold_cost), m_effects(std::move(effects)) {}
    virtual ~Card() {}
    unsigned int getManaCost() const { return m_gold_cost; }
    // Link the card to a board
    void linkBoard(std::weak_ptr<Board> board) { m_board = board; }
    void print() const;

    // Apply the effects of the card
    void applyEffects(Effect::ActivationPhase_e phase) const
    {
        for (const auto &effect : m_effects)
        {
            if (effect->getActivationPhase() == phase)
                effect->activate();
        }
    }

    Player *getOwner() { return m_owner; }
    // Get the board
    std::weak_ptr<Board> getBoard() { return m_board; }

    void setOwner(Player *owner) { m_owner = owner; }
};

#endif