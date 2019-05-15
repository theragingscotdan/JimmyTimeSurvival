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
		int haveKey = m_player->GetKeys();
		if (haveKey >= 2)
		{
			m_active = false;
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