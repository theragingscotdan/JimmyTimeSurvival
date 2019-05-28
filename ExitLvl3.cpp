#include "ExitLvl3.h"
#include "Framework/AssetManager.h"

ExitLvl3::ExitLvl3()
	: Exit()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/acessdenied.png"));

}

void ExitLvl3::Update(sf::Time _frameTime)
{
	if (m_player != nullptr)
	{
		// get the number of keys from player. if the number of keys is less than or equal
		// to 2 keys, swap the sprite
		int haveKey = m_player->GetKeys();
		if (haveKey >= 2)
		{
			//m_active = false;
			// swap the sprite to access granted
			m_sprite.setTexture(AssetManager::GetTexture("graphics/acessgranted.png"));
		}
	}
}

void ExitLvl3::Collide(GameObject& _collider)
{

}

void ExitLvl3::SetActive(bool _active)
{
	m_active = _active;
}
void ExitLvl3::SetPlayer(Player* _player)
{
	m_player = _player;
}