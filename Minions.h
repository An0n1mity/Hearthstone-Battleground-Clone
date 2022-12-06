#include "Cards.h"

// Minion is a type of card
class Minion : public Card
{
protected:
    // Minions have health and attack points
    unsigned int m_health_points;
    unsigned int m_attack_points;

public:
    Minion(unsigned int health_points, unsigned int attack_points) : Card(3), m_health_points(health_points), m_attack_points(attack_points) {}
    virtual ~Minion() {}
    void attackEnemy(Minion &enemy);
};
