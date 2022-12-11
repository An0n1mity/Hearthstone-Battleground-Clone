#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <experimental/memory>

#include "Effects.h"

class Player;
class Board;

class Card
{

protected:
    // The card's owner
    std::experimental::observer_ptr<Player> m_owner;
    // The card can be linked to a board
    std::experimental::observer_ptr<Board> m_board;
    const unsigned int m_gold_cost;
    // The card's effects
    std::vector<std::unique_ptr<Effect>> m_effects;
    virtual void printType() const = 0;

public:
    Card(unsigned int gold_cost, std::vector<std::unique_ptr<Effect>> effects = {}) : m_gold_cost(gold_cost), m_effects(std::move(effects)) {}
    virtual ~Card() {}
    unsigned int getManaCost() const { return m_gold_cost; }
    // Link the card to a board
    void linkBoard(std::experimental::observer_ptr<Board> board) { m_board = board; }
    void linkPlayer(std::experimental::observer_ptr<Player> player) { m_owner = player; }
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

    std::experimental::observer_ptr<Player> getOwner() const { return m_owner; }
    virtual int getRang() const = 0;
    // Get the board
    std::experimental::observer_ptr<Board> getBoard() { return m_board; }

    virtual void printName() const = 0;
};

#endif