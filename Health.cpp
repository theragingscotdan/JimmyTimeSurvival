
#include "Health.h"
#include "Framework/AssetManager.h"

Health::Health()
	: TextObject() // initialise parent class
	, m_player(nullptr)
{
	m_Text.setFont(AssetManager::GetFont("fonts/mainFont.ttf"));
	m_Text.setString("Health: 100");
	m_Text.setPosition(500, 0);

}

void Health::Update(sf::Time _frameTime)
{
	if (m_player != nullptr)
	{
		int health = m_player->GetHealth();
		m_Text.setString("Health: " + std::to_string(health));
	}

}

void Health::SetPlayer(Player* _player)
{
	m_player = _player;
}