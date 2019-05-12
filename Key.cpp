#include "Key.h"
#include "Framework/AssetManager.h"


Key::Key()
	:Pickup()
	, m_keys(0)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/keycard.png"));
}

void Key::OnPickup(Player& _player)
{
	m_active = false;
	m_keys++;

}

int Key::GetKeys()
{
	return m_keys;
}