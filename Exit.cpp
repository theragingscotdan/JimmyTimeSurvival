#include "Exit.h"
#include "Framework/AssetManager.h"

Exit::Exit()
	:SpriteObject()
	, m_player(nullptr)
	, m_level(nullptr)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/DoorClosed.png"));
}

void Exit::Update(sf::Time _frameTime)
{
	if (m_player != nullptr)
	{

	}
}

void Exit::Collide(GameObject& _collider)
{
	// only do something if the thing we touched is the player

	Player* castPlayer = dynamic_cast <Player*>(&_collider);
}

void Exit::SetPlayer(Player* _player)
{
	m_player = _player;
}

void Exit::SetLevel(Level* _level)
{
	m_level = _level;
}