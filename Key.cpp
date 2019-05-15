#include "Key.h"
#include "Framework/AssetManager.h"


Key::Key()
	:Pickup()
	
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/keycard.png"));
}

void Key::OnPickup(Player& _player)
{
	m_active = false;
	_player.SetKeys(1);


}

/*int Key::GetKeys()
{
	return m_keys;
} */