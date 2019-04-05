#include "Rusher.h"
#include "Framework/AssetManager.h"

Rusher::Rusher()
	:Enemy()
	, m_Charge(false)
{
	
	m_sprite.setTexture(AssetManager::GetTexture("graphics/buffalo.png"));
	
}

void Rusher::Update(sf::Time _frameTime)
{
	//m_player-> 
}

void Rusher::Collide(GameObject& _collider)
{
	
}
// rusher must move in a patrol path
// must have a vision area and cannot see the player outside this area
// if the player is in vision charge towards the player
// if it hits a wall while charging, stun it
// if it hits the player damage player