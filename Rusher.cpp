#include "Rusher.h"
#include "Framework/AssetManager.h"

Rusher::Rusher()
	:Enemy()
	, m_Charge(false)
	, m_position(0.0f, 0.0f)
{
	
	m_sprite.setTexture(AssetManager::GetTexture("graphics/buffalo.png"));
	
}

void Rusher::Update(sf::Time _frameTime)
{
	//m_player-> 
	//m_startPoint = m_currentPosition;
	m_secondsPassed += _frameTime.asSeconds();

	m_position = QuadEaseOut(m_secondsPassed, m_duration, m_startPoint, m_endPoint);

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