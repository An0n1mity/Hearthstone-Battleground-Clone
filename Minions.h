#ifndef MINIONS_H
#define MINIONS_H

#include "Cards.h"

// Minion is a type of card
class Minion : public Card
{
    static ::std::shared_ptr<Board> m_board;

protected:
    // Minions have health and attack points
    unsigned int m_health_points;
    unsigned int m_attack_points;

public:
    Minion(unsigned int health_points, unsigned int attack_points, std::vector<std::unique_ptr<Effect>> effects = {}) : Card(0, std::move(effects)), m_health_points(health_points), m_attack_points(attack_points) {}
    virtual ~Minion() {}
    void attackEnemy(Minion &enemy);

    // Summon a minion of a type T on the board
    template <typename T>
    static void summonMinion(std::shared_ptr<Board> board)
    {
        // Create a new minion of type T
        std::unique_ptr<Minion> minion = std::make_unique<T>();
    }
};

#endif