#include "HealthKit.h"
#include "Framework/AssetManager.h"


HealthKit::HealthKit()
	:Pickup()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/HealthKit.png"));
}

void HealthKit::OnPickup(Player& _player)
{
	m_active = true; // if active
	// if the player has 100hp, do nothing
	if (_player.GetHealth() == 100)
	{
		
	}
	// if between 50 and 99 hp, set the player's health to 100 and despawn
	else if	(_player.GetHealth() < 100 && _player.GetHealth() >= 50)
	{
		// disappear
		m_active = false;
		_player.SetHealth(100);
	}
	// if health is between 1 and 49, add 50 to health
	else if (_player.GetHealth() < 50 && _player.GetHealth() > 0)
	{
		// disappear
		m_active = false;
		_player.AddHealth(50);
	} 
}