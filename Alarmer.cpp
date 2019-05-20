#include "Alarmer.h"
#include "Framework/AssetManager.h"

Alarmer::Alarmer()
	:Enemy()
	,m_position(0.0f, 0.0f)
	, m_state(STATE_PASSIVE)
	, m_hasVision(false)
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

void Alarmer::UpdateState(State _state)
{
	m_state = _state;
	{
		switch (_state)
		{
			case STATE_BLIND
			
			
			
			break;

			case STATE_VISION
				if (m_playerseen == true)
				{
					m_state(STATE_SPOTTED);
				}

				break;
			case STATE_SPOTTED
			
				// 
			
			break;

				case STATE_ALERT

					// alert all nearby enemies
					break;
			
		}

	};
}