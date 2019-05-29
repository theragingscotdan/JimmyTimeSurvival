#include "Key.h"
#include "Framework/AssetManager.h"


Key::Key()
	:Pickup()
	, m_keyCollect()
	
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/keycard.png"));
	m_keyCollect.setBuffer(AssetManager::GetSoundBuffer("audio/KeyCollect.wav"));
}

void Key::OnPickup(Player& _player)
{
	m_active = false;
	_player.SetKeys(1);
	m_keyCollect.play();


}
