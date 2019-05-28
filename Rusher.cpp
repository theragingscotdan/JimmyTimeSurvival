#include "Rusher.h"
#include "Framework/AssetManager.h"

Rusher::Rusher()
	:Enemy()
	, m_charge(false)
	, m_position(0.0f, 0.0f)
{
	
	m_sprite.setTexture(AssetManager::GetTexture("graphics/rusher.png"));

	// this modifier will be used to set the end point below
	m_modifier = sf::Vector2f(300.0f, 0.0f);
	
	
	
}

void Rusher::Update(sf::Time _frameTime)
{
	//m_player-> 
	m_secondsPassed += _frameTime.asSeconds();

	// using Quadratic Interpolation to move the rusher
	m_position = QuadEaseOut(m_secondsPassed, m_duration, m_startPoint, m_endPoint);
	

	// in order to get the end point, subtract the start point from the modifier
	m_endPoint = m_startPoint - m_modifier;
		
	// 

	if (m_secondsPassed >= m_duration)
	{
		// reset seconds passed to 0
		m_secondsPassed = 0;

		// switch the start and end point and multiply the modifier by -1.0f to 
		// reverse the direction and correctly set the end point
		sf::Vector2f oldStart = m_startPoint;
		sf::Vector2f oldEnd = m_endPoint;
		m_modifier = (m_modifier * -1.0f);
		m_startPoint = oldEnd;
		m_endPoint = oldStart;
	}

	m_sprite.setPosition(m_position);

	 // TODO: get postion via a setter from level
	// add a position vector to move
	//m_startPoint = m_sprite.getPosition();
	//m_endPoint = m_startPoint += (x, y);

	MovingObject::Update(_frameTime);
}


void Rusher::Collide(GameObject& _collider)
{
	
}
// rusher must move in a patrol path
// must have a vision area and cannot see the player outside this area
// if the player is in vision charge towards the player
// if it hits a wall while charging, stun it
// if it hits the player damage player

void Rusher::SetStartPosition(sf::Vector2f _start)
{
	m_startPoint = _start;
}

void Rusher::SetEndPositon(sf::Vector2f _end)
{
	m_endPoint = _end;
}


	 