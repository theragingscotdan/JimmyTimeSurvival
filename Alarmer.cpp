#include "Alarmer.h"
#include "Framework/AssetManager.h"

Alarmer::Alarmer()
	:Enemy()
	,m_position(0.0f, 0.0f)
	, m_state(STATE_BLIND)
	, m_hasVision(false)
	, m_timeTillTransition(0.0f)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/rabbit.png"));

}

void Alarmer::Update(sf::Time _frameTime)
{
	UpdateState(m_state);
	MovingObject::Update(_frameTime);
}

	

void Alarmer::SightTime(sf::Time _frameTime)
{
	if (!m_hasVision)
	{
		m_timeTillTransition += _frameTime.asSeconds();

		if (m_timeTillTransition <= 5.0f)
		{
			STATE_BLIND;
		}
		else
		{
			STATE_VISION;
			m_timeTillTransition = 0;
		}
	}
	
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
		case STATE_BLIND :

				//SightTime();
		
			
			break;

		case STATE_VISION :
				if (m_playerseen == true)
				{
					//m_state(STATE_SPOTTED);
				}
				
				break;
		case STATE_SPOTTED :
			
				// 
			
			break;

		case STATE_ALERT :

					// alert all nearby enemies
					break;
			
				default: STATE_BLIND;
					break;
		}

	};
}