#include "Alarmer.h"
#include "Framework/AssetManager.h"

Alarmer::Alarmer()
	:Enemy()
	,m_position(0.0f, 0.0f)
	, m_state(STATE_PASSIVE)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/rabbit.png"));

}

void Alarmer::Collide(GameObject& _collider)
{

}

void Alarmer::SetStartPosition(sf::Vector2f _start)
{
	m_position = _start;
}

enum State
{
	switch (m_state)
	{
		case STATE_PASSIVE
		{

		}
		break;

		case STATE_SPOTTED
		{

		}
		break;

		case STATE_ALERT
		{

		}
	}
}