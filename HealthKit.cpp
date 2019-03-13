#include "HealthKit.h"
#include "Framework/AssetManager.h"


HealthKit::HealthKit()
	:Pickup()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/HealthKit.png"));
}

void HealthKit::OnPickup(Player& _player)
{

}