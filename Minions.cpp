#include "Minions.h"
#include "MinionsTribes.h"

void Minion::attackEnemy(Minion &enemy)
{
	// Check if the enemy is dead
	int enemy_health = enemy.getHealth();
	int attack_points = m_attack_points;
	if (enemy_health - attack_points <= 0)
		enemy.m_health_points = 0;
	else
		enemy.m_health_points -= m_attack_points;
}
