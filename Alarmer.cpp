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

void Alarmer::PlayerLocation(sf::Vector2f playerPos, sf::Vector2f enemyPos)
{
	// https://www.gamedev.net/forums/topic/671131-sfml-distance-between-player-and-enemy/
	//playerPos = m_player->GetPosition();
	//enemyPos = this->GetPosition();
	//float distx = m_player->GetPosition().x - this->GetPosition().y; // distx can be negative.
	//float disty = m_player->GetPosition().y - this->GetPosition().y; // disty can be negative.
	float distx = playerPos.x - enemyPos.y; // distx can be negative.
	float disty = playerPos.y - enemyPos.y; // disty can be negative.

	float distx2 = distx * distx; // distx2 is ALWAYS non-negative (+2 * +2 gives +4, 0 * 0 gives 0, -3 * -3 gives +9)
	float disty2 = disty * disty; // disty2 is ALWAYS non-negative

	float dxy2 = distx2 + disty2; // dxy2 is ALWAYS non-negative
	float dxy = sqrt(dxy2);

	float distance = (abs(sqrt(((playerPos.x - enemyPos.x) * (playerPos.x - enemyPos.x)) + ((playerPos.y - enemyPos.y) * (playerPos.y - enemyPos.y)))));
	
	if (distance <= 100 && m_state == STATE_VISION)
	{
		m_playerseen = true;
	}
	
	//if
	 {

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
			if (m_player != nullptr)
			{
				PlayerLocation(m_player->GetPosition(), this->GetPosition());

				//if (m_player->GetPosition();
				if (m_playerseen == true)
				{
					//m_sprite.setTexture(AssetManager::GetTexture("graphics/toolkit.png"));
					m_state = STATE_SPOTTED;
					//m_sprite.setTexture(AssetManager::GetTexture("graphics/rabbit"));
				}
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