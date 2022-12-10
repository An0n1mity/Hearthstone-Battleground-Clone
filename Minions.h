#ifndef MINIONS_H
#define MINIONS_H

#include "Cards.h"

// Minion is a type of card
class Minion : public Card
{
    static ::std::shared_ptr<Board> m_board;

protected:
    // Minions have a rank
    const unsigned int m_rank;
    // Minions have health and attack points
    unsigned int m_health_points;
    unsigned int m_attack_points;

public:
    Minion(const unsigned int rank, unsigned int health_points, unsigned int attack_points, std::vector<std::unique_ptr<Effect>> effects = {}) : Card(0, std::move(effects)), m_rank(rank), m_health_points(health_points), m_attack_points(attack_points) {}
    virtual ~Minion() {}
    void attackEnemy(Minion &enemy);

    // Summon a minion of a type T on the board
    template <typename T>
    static void summonMinion(std::weak_ptr<Board> board, Card *card)
    {
        // Create a new minion of type T
        std::unique_ptr<Minion> minion = std::make_unique<T>();
        // Convert the weak pointer to a shared pointer
        std::shared_ptr<Board> board_ptr = board.lock();
        // Update owner and board
        Player *pl = card->getOwner();
        minion->setOwner(card->getOwner());
        // Add the minion to the board
        // Dynamic cast the minion to a card
        std::unique_ptr<Card> card_ptr = std::move(minion);
        board_ptr->addCard(card_ptr);
    }

    // Get the type of the minion
    virtual std::string getType() const = 0;
    // Get the rank of the minion
    virtual int getRang() const { return m_rank; }
};

#endif