#ifndef MINIONS_H
#define MINIONS_H

#include "Cards.h"
//#define MINIONS_DEBUG 1

// Minion is a type of card
class Minion : public Card
{
    public:

    // State of the minion 
    enum State{
	ATTACKING,
	DEFENDING,
	IDLING
    };
protected:
    // Minions have a rank
    const unsigned int m_rank;
    // Minions have health and attack points
    int m_health_points;
    unsigned int m_attack_points;
    // Minion have a description for the effects 
    std::string m_effect_description;
    enum State m_state;

public:
    Minion(const unsigned int rank, unsigned int health_points, unsigned int attack_points, std::vector<std::unique_ptr<Effect>> effects = {}) : Card(3, std::move(effects)), m_rank(rank), m_health_points(health_points), m_attack_points(attack_points), m_state(IDLING) {}
    virtual ~Minion() {}
    void attackEnemy(Minion &enemy);
    void attackEnemy(Player &enemy);
    int getHealth() const { return m_health_points; }
    enum State getState() const { return m_state; }
    void setState(enum State state) { m_state = state; }
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
        minion->linkBoard(board);
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

    // Buff the health points of a minion
    static void buffHealthPoint(Card *card, unsigned int buff)
    {
#if MINIONS_DEBUG
	std::cout << "[MINIONS DEBUG]: Called from " << __FILE__ << " line " << __LINE__ << " Minion::buffAttackPoint " << '\n';
#endif
		Minion *minion = dynamic_cast<Minion *>(card);
		minion->m_health_points += buff;
    }

    // Get the type of the minion
    virtual std::string getType() const = 0;
    // Get the rank of the minion
    virtual int getRang() const { return m_rank; }
    // Return a bool if the minion has an effect of type 
    bool hasEffect(std::string effect_type)const{
		for (auto &effect : m_effects)
		{
		    if (effect_type == "TAUNT")
		    {
			// Check if the effect is of type T
			if (dynamic_cast<Taunt *>(effect.get()))
			    return true;
		    }
		}
		return false;
	}
};

#endif
