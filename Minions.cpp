#include "Minions.h"

void Minion::attackEnemy(Minion &enemy)
{
    enemy.m_health_points -= m_attack_points;
}