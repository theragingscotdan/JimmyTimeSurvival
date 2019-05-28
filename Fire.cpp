#include "Fire.h"
#include "Framework/AssetManager.h"

Fire::Fire()
	: Obstacle()
	, m_secondsPerStand(0.0f)
	, m_player(nullptr)
	, m_canDamage(false)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/fire.png"));
}

void Fire::Update(sf::Time _frameTime)
{
	if (!m_canDamage) // if the player cannot take damage
	{
		m_secondsPerStand += _frameTime.asSeconds(); // start the timer for m_secondsPerStand
		// If we have movement waiting to be processed,
		if (m_secondsPerStand > 2.0f)  // If the time less than 2 seconds
		{
			m_canDamage = true; // allow the player to take damage
			m_secondsPerStand = 0.0f; // reset the timer back to 0

		}
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