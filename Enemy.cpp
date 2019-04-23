#include "Enemy.h"

Enemy::Enemy()
	:MovingObject()
	, m_player(nullptr)
	, m_dead(false)
	, m_playerseen(false)
{

}

void Enemy::Update(sf::Time _frameTime)
{

}

void Enemy::Collide(GameObject& _collider)
{
	
}

void Enemy::SetActive(bool _active)
{
	m_active = _active;
}

double Enemy::LinearInterpolate(double x0, double x1, double y0, double y1, double x)
{
	return y0 + (x - x0) * (y1 - y0) / (x1 - x0);
}