#include "Player.h"
#include "Wall.h"
#include "Spikes.h"
#include "Fire.h"
#include "Framework/AssetManager.h"

#define SPEED 250.0f

Player::Player()
	: MovingObject()
	, m_level(nullptr)
	, m_health(100)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/playerPlaceHold/playerStandDown.png"));
}

void Player::Update(sf::Time _frameTime)
{
	// first, assume no keys are pressed
	m_velocity.x = 0.0f;
	m_velocity.y = 0.0f;

	// use the keyboard function to check which keys are currently held down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_velocity.y = -SPEED;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_velocity.x = -SPEED;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_velocity.y = SPEED;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_velocity.x = SPEED;
	}

	// call the update function manually on the parent class
	// This will actually move the character

	MovingObject::Update(_frameTime);

	// process animations
	//m_animationSystem.Update(_frameTime);

}

void Player::Collide(GameObject& _collider)
{
	// only do something if the object is a wall
	Wall* wallCollider = dynamic_cast<Wall*>(&_collider);
	Spikes* spikeCollider = dynamic_cast<Spikes*>(&_collider);
	Fire* fireCollider = dynamic_cast<Fire*>(&_collider);


	// if it was a wall we hit, we need to move ourselves
	//outside the wall's bounds, aka back where we were
	if (wallCollider != nullptr)
	{
		// we did hit a wall!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

		// Party time!

		// return to your previous position that we just
		// moved away from this frame
		m_sprite.setPosition(m_previousPosition);
	}
	else if (spikeCollider != nullptr)
	{

	}
	else if (fireCollider != nullptr)
	{
		m_health -= 10;
	}
}

void Player::setLevel(Level* _newLevel)
{
	m_level = _newLevel;
}

int Player::GetHealth()
{
	return m_health;
}