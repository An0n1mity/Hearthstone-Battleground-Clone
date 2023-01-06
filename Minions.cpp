#include "Minions.h"
#include "MinionsTribes.h"

void Minion::attackEnemy(Minion &enemy)
{
#if MINIONS_DEBUG
    std::cout << "[MINIONS DEBUG]: Called from " << __FILE__ << " line " << __LINE__ << " Minion::attackEnemy " << '\n';
#endif
	// Activate the effect of the minion on attack 
	enemy.applyEffects(Effect::ON_DAMAGE);
	// Check if the enemy is dead
	int enemy_health = enemy.getHealth();
	int attack_points = m_attack_points;
	if (enemy_health - attack_points <= 0)
		enemy.m_health_points = 0;
	else
		enemy.m_health_points -= m_attack_points;
}
