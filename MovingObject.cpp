#include "MovingObject.h"

MovingObject::MovingObject()
	:SpriteObject()
	, m_velocity(0.0f,0.0f)
	, m_previousPosition(0.0f,0.0f)
{

}

void MovingObject::Update(sf::Time _frameTime)
{
	sf::Vector2f currentPosition = m_sprite.getPosition();

	// record our current position as previous position
	m_previousPosition = currentPosition;

	// calculat the amount moved
	sf::Vector2f amountMoved = m_velocity * _frameTime.asSeconds();

	// calculate new position
	sf::Vector2f newPosition = currentPosition + amountMoved;

	// set our sprite to this new position
	m_sprite.setPosition(newPosition);
}