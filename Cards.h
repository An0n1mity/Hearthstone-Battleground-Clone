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
    // Id
    int m_id;
    // The card's owner
    std::experimental::observer_ptr<Player> m_owner;
    // The card can be linked to a board
    std::experimental::observer_ptr<Board> m_board;
    const unsigned int m_gold_cost = 3;
    unsigned int m_gold_sell = 1;
    // The card's effects
    std::vector<std::unique_ptr<Effect>> m_effects;
    virtual void printType() const = 0;

public:
    Card(unsigned int gold_cost, std::vector<std::unique_ptr<Effect>> effects = {}) : m_gold_cost(gold_cost), m_effects(std::move(effects))
    {
        static int id = 0;
        m_id = id++;
    }
    virtual ~Card() {}
    unsigned int getGoldCost() const { return m_gold_cost; }
    unsigned int getGoldSell() const { return m_gold_sell; }
    void setGoldSell(unsigned int gold_sell) { m_gold_sell = gold_sell; }
    int getId() const { return m_id; }
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

    // get Effects of the card
    std::vector<std::unique_ptr<Effect>> &getEffects() { return m_effects; }

    std::experimental::observer_ptr<Player> getOwner() const { return m_owner; }
    virtual int getRang() const = 0;
    // Get the board
    std::experimental::observer_ptr<Board> getBoard() { return m_board; }

    virtual void printName() const = 0;
    virtual const std::string getName() const = 0;
};

#endif
