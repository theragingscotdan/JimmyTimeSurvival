
#include "KeyText.h"
#include "Framework/AssetManager.h"

KeyText::KeyText()
	: TextObject() // initialise parent class
	, m_player(nullptr)
{
	m_Text.setFont(AssetManager::GetFont("fonts/mainFont.ttf"));
	m_Text.setString("Keys: 0");
	m_Text.setPosition(300, 300);

}

void KeyText::Update(sf::Time _frameTime)
{
	if (m_player != nullptr)
	{
		int keys = m_player->GetKeys();
		m_Text.setString("keys: " + std::to_string(keys));
	}

}

void KeyText::SetPlayer(Player* _player)
{
	m_player = _player;
}