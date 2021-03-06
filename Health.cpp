
#include "Health.h"
#include "Framework/AssetManager.h"

Health::Health()
	: TextObject() // initialise parent class
	, m_player(nullptr)
{
	m_Text.setFont(AssetManager::GetFont("fonts/mainFont.ttf"));
	m_Text.setString("Health: 100");
	m_Text.setPosition(500, 0);
	//m_Text.setFillColor(sf::Color::Blue);

}

void Health::Update(sf::Time _frameTime)
{
	// if player is not nullptr, get their health then draw that value on screen
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