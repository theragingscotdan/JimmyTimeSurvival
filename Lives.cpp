
#include "Lives.h"
#include "Framework/AssetManager.h"

Lives::Lives()
	: TextObject() // initialise parent class
	, m_player(nullptr)
{
	m_Text.setFont(AssetManager::GetFont("fonts/mainFont.ttf"));
	m_Text.setString("Lives: 0");
	m_Text.setPosition(1500, 0);

}

void Lives::Update(sf::Time _frameTime)
{
	if (m_player != nullptr)
	{
		int lives = m_player->GetLives();
		m_Text.setString("Lives: " + std::to_string(lives));
	}

}

void Lives::SetPlayer(Player* _player)
{
	m_player = _player;
}