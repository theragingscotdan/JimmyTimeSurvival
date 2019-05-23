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
	UpdateState(m_state, _frameTime);
	MovingObject::Update(_frameTime);
}

	

void Alarmer::SightTime(sf::Time _frameTime)
{
	m_timeTillTransition += _frameTime.asSeconds();
	if (!m_hasVision)
	{
		//m_timeTillTransition += _frameTime.asSeconds();

		if (m_timeTillTransition <= 5.0f)
		{
			m_state = STATE_BLIND;
		}
		else
		{
			m_hasVision = true;
			m_state = STATE_VISION;
			m_timeTillTransition = 0;
		}
	}
	else
	{
		if (m_timeTillTransition <= 5.0f)
		{
			m_state = STATE_VISION;
		}
		else
		{
			m_hasVision = false;
			m_state = STATE_BLIND;
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

void Alarmer::UpdateState(State m_state, sf::Time _time)
{
	//m_state = _state;
	//sf::Time time;
	//time = m_timeTillTransition;
	{
		switch (m_state)
		{
		case STATE_BLIND :

				SightTime(_time);
			
				
				m_sprite.setTexture(AssetManager::GetTexture("graphics/rabbit.png"));

		//	} 
			
			
			break;

		case STATE_VISION :

			m_sprite.setTexture(AssetManager::GetTexture("graphics/rabbit"));
			SightTime(_time);
				if (m_playerseen == true)
				{
					//m_state(STATE_SPOTTED);
					//m_sprite.setTexture(AssetManager::GetTexture("graphics/rabbit"));
				}
				
				break;
		case STATE_SPOTTED :
			
				// 
			//if 
			
			break;

		case STATE_ALERT :

					// alert all nearby enemies
					break;
			
				default: STATE_BLIND;
					break;
		}

	};
}