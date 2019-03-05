#include "Fire.h"
#include "Framework/AssetManager.h"

Fire::Fire()
	: Obstacle()
	, m_secondsPerStand(0.0f)
	, m_player(nullptr)
	, m_canDamage(false)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/firePlaceHold.png"));
}

void Fire::Update(sf::Time _frameTime)
{
	m_secondsPerStand += _frameTime.asSeconds();
	// If we have movement waiting to be processed,
	if (!m_canDamage && m_secondsPerStand > 2.0f) // if the player cannot take damage and time is less than 2 seconds
	{
		m_canDamage = true; // allow the player to take damage
		m_secondsPerStand = 0.0f;

	}

}

bool Fire::GetCanDamage()
{
	return m_canDamage;
}

void Fire::SetCanDamage(bool _damage)
{
	m_canDamage = _damage;
}