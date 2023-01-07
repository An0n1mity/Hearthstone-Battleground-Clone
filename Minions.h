#ifndef MINIONS_H
#define MINIONS_H

#include "Cards.h"
#define MINIONS_DEBUG 1

// Minion is a type of card
class Minion : public Card
{

protected:
    // Minions have a rank
    const unsigned int m_rank;
    // Minions have health and attack points
    unsigned int m_health_points;
    unsigned int m_attack_points;
    // Minion have a description for the effects 
    std::string m_effect_description;

public:
    Minion(const unsigned int rank, unsigned int health_points, unsigned int attack_points, std::vector<std::unique_ptr<Effect>> effects = {}) : Card(3, std::move(effects)), m_rank(rank), m_health_points(health_points), m_attack_points(attack_points) {}
    virtual ~Minion() {}
    void attackEnemy(Minion &enemy);
    void attackEnemy(Player &enemy);
    unsigned int getHealth() const { return m_health_points; }
    unsigned int getAttack() const { return m_attack_points; }
    std::string getEffectDescription() const { return m_effect_description; }
    // Summon a minion of a type T on the board
    template <typename T>
    static void summonMinion(std::experimental::observer_ptr<Board> board, Card *card)
    {
#if MINIONS_DEBUG
	std::cout << "[MINIONS DEBUG]: Called from " << __FILE__ << " line " << __LINE__ << " Minion::summonMinion " << '\n';
#endif
        // Create a new minion of type T
        std::unique_ptr<Card> minion = std::make_unique<T>();
        // Update owner and board
        std::experimental::observer_ptr<Player> player = card->getOwner();
        minion->linkPlayer(player);
        //  Add the minion to the board
        board->addCardLeft(minion);
    }

    // Buff the attack points of a minion 
    static void buffAttackPoint(Card *card, unsigned int buff)
    {
#if MINIONS_DEBUG
	std::cout << "[MINIONS DEBUG]: Called from " << __FILE__ << " line " << __LINE__ << " Minion::buffAttackPoint " << '\n';
#endif
		Minion *minion = dynamic_cast<Minion *>(card);
		minion->m_attack_points += buff;
    }

    // Get the type of the minion
    virtual std::string getType() const = 0;
    // Get the rank of the minion
    virtual int getRang() const { return m_rank; }
};

#endif
