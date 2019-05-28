#include "ExitLvl2.h"
#include "Framework/AssetManager.h"

ExitLvl2::ExitLvl2()
	: Exit()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/OutofOrder.png"));
	
}

void ExitLvl2::Update(sf::Time _frameTime)
{
	if (m_player != nullptr)
	{
		bool haveTool = m_player->GetToolkit();
		if (haveTool == true)
		{
			m_active = false;
		}
	}
}

void ExitLvl2::Collide(GameObject& _collider)
{
	
}

void ExitLvl2::SetActive(bool _active)
{
	m_active = _active;
}



