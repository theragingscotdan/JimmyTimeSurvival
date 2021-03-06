#include "Alarmer.h"
#include "Framework/AssetManager.h"

Alarmer::Alarmer()
	:Enemy()
	,m_position(0.0f, 0.0f)
	, m_state(STATE_BLIND)
	, m_hasVision(false)
	, m_timeTillTransition(0.0f)
	, m_player(nullptr)
	, m_alarmSound()
	, m_SpottedTime(0.0f)
	, m_playAnimation(false)
{
	//m_sprite.setTexture(AssetManager::GetTexture("graphics/rabbit.png"));
	m_alarmSound.setBuffer(AssetManager::GetSoundBuffer("audio/AlarmerAlert.wav"));

	m_animationSystem.SetSprite(m_sprite);

	// create the animation. each add frame adds to the animation
	Animation& Alert = m_animationSystem.CreateAnimation("Alert");
	Alert.AddFrame(AssetManager::GetTexture("graphics/Alarmer/AlarmerAlertP1.png"));
	Alert.AddFrame(AssetManager::GetTexture("graphics/Alarmer/AlarmerAlertP2.png"));
	Alert.AddFrame(AssetManager::GetTexture("graphics/Alarmer/AlarmerAlertP3.png"));
	Alert.AddFrame(AssetManager::GetTexture("graphics/Alarmer/AlarmerAlertP4.png"));
	Alert.SetPlayBackSpeed(10);
	Alert.SetLoop(true);
	
	

	

}

void Alarmer::Update(sf::Time _frameTime)
{
	m_animationSystem.Update(_frameTime);
	UpdateState(m_state, _frameTime);
	MovingObject::Update(_frameTime);
}

	

void Alarmer::SightTime(sf::Time _frameTime)
{
		
	m_timeTillTransition += _frameTime.asSeconds();
	if (!m_hasVision)
	{
		// this switches between blind and vision. If the time since last transition is
		// less than or equal to 8 seconds, state is blind

		if (m_timeTillTransition <= 8.0f)
		{
			m_state = STATE_BLIND;
		}
		else
		{
			// set has vision to true, change state to vision and timeTillTransition to 0
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
	
	// work out the magnitude between the player and the alarmer
	float distance = (abs(sqrt(((playerPos.x - enemyPos.x) * (playerPos.x - enemyPos.x)) + ((playerPos.y - enemyPos.y) * (playerPos.y - enemyPos.y)))));

	if (m_state == STATE_VISION)
	{
		if ((distance <= 200))// || dxy <= 200.0f)) // && m_state == STATE_VISION)
		{
			m_playerSeen = true;
			m_state = STATE_SPOTTED;
		}
		else if ((distance > 200))// || dxy >= 200.0f)) // && m_state == STATE_VISION)
		{
			m_playerSeen = false;
			//m_state = STATE_VISION;
		}
	}
	//else 
	if (m_state == STATE_ALERT)
	{
		if ((distance > 200))// || dxy >= 200.0f)) //&& m_state == STATE_ALERT)
		{
			// the alarmer can no longer see the player and so revert back to a different state
			m_state = STATE_VISION;
		}
		else if ((distance <= 200))// || dxy <= 200.0f))
		{
			m_state = STATE_ALERT;
			//m_sprite.setTexture(AssetManager::GetTexture("graphics/spikesPlacehold.png"));
		}
	}
}

void Alarmer::SeenPlayer(sf::Time _frametime)
{
	if (m_playerSeen) // if the player is seen
	{
		m_SpottedTime += _frametime.asSeconds(); // add 1 second every frame

		// if 2 seconds have passed reset the timer and switch to alert state 
		if (m_SpottedTime >= 2.0f) 
		{
			m_SpottedTime = 0.0f;
			m_state = STATE_ALERT;
		}
		//else if (m_SpottedTime <= 0)
	}
	else if (!m_playerSeen)
	{
		//m_state = STATE_VISION;
		m_SpottedTime = 0.0f;
		m_playerSeen = false;
		
	}
	
}

void Alarmer::Collide(GameObject& _collider)
{

}

void Alarmer::SetStartPosition(sf::Vector2f _start)
{
	m_position = _start;
}

void Alarmer::SetPlayer(Player* _player)
{
	m_player = _player;
}

void Alarmer::UpdateState(State m_state, sf::Time _time)//, Player* _player)
{
	// this is a finite state machine which controls the AI for the Alarmer
	// it uses an Enum for each individual state 
	{
		switch (m_state)
		{
		case STATE_BLIND : // if the current state is blind

				SightTime(_time); // run the SightTime function and pass in _time
			
				
				m_sprite.setTexture(AssetManager::GetTexture("graphics/Alarmer/AlarmerBlind.png"));

		//	} 
			
			
			break;

			// during the vision state, the alarmer can see the player and will swap states
			// if it sees the player
		case STATE_VISION : // if the current state is vision

			m_sprite.setTexture(AssetManager::GetTexture("graphics/Alarmer/AlarmerVision.png"));
			SightTime(_time);
			if (m_player != nullptr)
			{
				// run PlayerLocation() passing in the player's position and the position
				// of the alarmer
				PlayerLocation(m_player->GetPosition(), this->GetPosition()); 

			}
				
				break;

				// this is a transitional state 
		case STATE_SPOTTED :
			m_sprite.setTexture(AssetManager::GetTexture("graphics/Alarmer/AlarmerSpotted1.png"));

				// 
			//if 
			m_playAnimation = false;
			SeenPlayer(_time);

			break;

			// the alarmer has noticed the player due to them staying near for too long
			// and this is alerting.
		case STATE_ALERT :

			PlayerLocation(m_player->GetPosition(), this->GetPosition());
			//m_sprite.setTexture(AssetManager::GetTexture("graphics/spikesPlacehold.png"));

			// play the alert animation
			m_animationSystem.Play("Alert");
		
			
			// disable the player's ability to attack
			m_player->SetCanAttack(false);
			
			// alert all nearby enemies
			//SeenPlayer(_time);
			if (m_alarmSound.getStatus() != sf::SoundSource::Status::Playing)
				m_alarmSound.play();
			//m_playingSound = true;
			
					break;
			
				default: STATE_BLIND; // the default state is set to blind
					break;
		}

	};
}