#include "Spikes.h"
#include "Framework/AssetManager.h"

Spikes::Spikes()
	: Obstacle()
{
	// set sprite to spikes
	m_sprite.setTexture(AssetManager::GetTexture("graphics/spikes1.png"));
}
void Spikes::Collider(GameObject&_collider)
{

}