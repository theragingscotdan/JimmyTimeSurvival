#include "ExitLvl2.h"
#include "Framework/AssetManager.h"

ExitLvl2::ExitLvl2()
	: Exit()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/DoorOpen.png"));
}

void ExitLvl2::Update(sf::Time _frameTime)
{
	if (m_player != nullptr)
	{
		bool haveKey = m_player->GetToolkit();
		if (haveKey == true)
		{
			m_sprite.setTexture(AssetManager::GetTexture("graphics/DoorOpen.png"));
		}
	}
}

void ExitLvl2::Collide(GameObject& _collider)
{

}