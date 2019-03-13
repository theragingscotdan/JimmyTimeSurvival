#include "HealthKit.h"
#include "Framework/AssetManager.h"


HealthKit::HealthKit()
	:Pickup()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/HealthKit.png"));
}

void HealthKit::OnPickup(Player& _player)
{
	if (_player.GetHealth() == 100)
	{
		
	}
	else if	(_player.GetHealth() < 100 && _player.GetHealth() >= 50)
	{
		// disappear
		m_active = false;
		_player.SetHealth(100);
	}
	else if (_player.GetHealth() < 50 && _player.GetHealth() > 0)
	{
		// disappear
		m_active = false;
		_player.AddHealth(50);
	} 
}