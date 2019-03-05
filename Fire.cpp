#include "Fire.h"
#include "Framework/AssetManager.h"

Fire::Fire()
	: Obstacle()
	, m_secondsPerStand(0)
	, m_stand(false)
	, m_player(nullptr)
	, m_canDamage(false)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/firePlaceHold.png"));
}

void Fire::Update(sf::Time _frameTime)
{
	m_secondsPerStand += _frameTime.asSeconds();
	// If we have movement waiting to be processed,
	if (!m_canDamage && m_secondsPerStand > 2.0f)
	{
		m_canDamage = true;
		m_secondsPerStand = 0;

	}

}

bool Fire::GetStand()
{
	return m_stand;
}
void Fire::SetStand(bool _stand)
{
	m_stand = _stand;
} 

bool Fire::GetCanDamage()
{
	return m_canDamage;
}

void Fire::SetCanDamage(bool _damage)
{
	m_canDamage = _damage;
}