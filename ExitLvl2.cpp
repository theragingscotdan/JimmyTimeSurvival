#include "ExitLvl2.h"
#include "Framework/AssetManager.h"

ExitLvl2::ExitLvl2()
	: Exit()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/DoorOpen"));
	
}

void ExitLvl2::Update(sf::Time _frameTime)
{
	if (m_player != nullptr)
	{
		bool haveKey = m_player->GetToolkit();
		if (haveKey == true)
		{
			m_active = false;
		}
	}
}

void ExitLvl2::Collide(GameObject& _collider)
{
	/*Player* castPlayer = dynamic_cast <Player*>(&_collider);

	if (castPlayer != nullptr)
	{
		
		if (castPlayer->GetToolkit() == true)
		{
			m_active = false;
		}
		else
		{
			
		}
	} */
}

void ExitLvl2::SetActive(bool _active)
{
	m_active = _active;
}



