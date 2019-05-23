#include "Toolbox.h"
#include "Framework/AssetManager.h"

Toolbox::Toolbox()
	: Pickup()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/toolbox1.png"));
}

void Toolbox::OnPickup(Player& _player)
{
	// disappear
	m_active = false;

	_player.SetToolkit(true);
}