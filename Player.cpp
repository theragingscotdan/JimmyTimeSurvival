#include "Player.h"
#include "Framework/AssetManager.h"

#define SPEED 300.0f

Player::Player()
	: MovingObject()
	, m_level(nullptr)
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

}

void Player::setLevel(Level* _newLevel)
{
	m_level = _newLevel;
}