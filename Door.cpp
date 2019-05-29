#include "Door.h"
#include "Framework/AssetManager.h"

Door::Door()
	: SpriteObject()
	, m_player(nullptr)

{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/door.png"));
	
}

void Door::Update(sf::Time _frameTime)
{

}

void Door::Collide(GameObject&_collider)
{

}

void Door::SetActive(bool _active)
{
	m_active = _active;
}
