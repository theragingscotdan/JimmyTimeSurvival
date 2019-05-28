#include "Bullet.h"
#include "Player.h"
#include "Wall.h"
#include "Framework/AssetManager.h"

#define SPEED 300f;
#define DISTANCE 400f;

Bullet::Bullet()
	: MovingObject()
	, m_bulletSpawn(0.0f, 0.0f)
	, m_firedTime(0.0f)
	, m_distanceTravelled(0.0f)
	, m_initialPosition(0.0f, 0.0f)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/bullet.png"));
	//sf::Vector2f m_initialPosition = m_sprite.getPosition();

}

void Bullet::Update(sf::Time _frameTime)
{
	//sf::Vector2f m_currentPosition;
	//sf::Vector2f m_initialPosition = m_sprite.getPosition();
	//if ()
	if (m_active)
	{
		//sf::Vector2f m_initialPosition = m_sprite.getPosition();
		m_firedTime += _frameTime.asSeconds();
		//m_bullet.
		//m_bullet.
		// 
		//m_currentPosition += sf::Vector2f(0.0f, 0.5f);
		m_velocity = sf::Vector2f(0.0f, 500.0f);

		//m_distanceTravelled += 1.0f;
		if (m_firedTime >= 1.25f)
		{
			m_active = false;
		}
		
		// i know the distance due to having m_sprite having position. Thus, i can use this to determine how far the bullet has travelled from the shooter
		// then use this to despawn the bullet after a certain distance
		/*if ((m_initialPosition.y - m_sprite.getPosition().y) >= 10.0f)
		//if ((m_sprite.getPosition().y  - m_initialPosition.y) >= 10.0f)
		{
			Despawn();
		} */
		// todo: try subtracting the initial value from the current value and compare it to a number
		//m_newPosition;
		//m_sprite.setPosition(m_currentPosition);
		
	}

	MovingObject::Update(_frameTime);
}

void Bullet::Collide(GameObject& _collider)
{
	// dynamic cast to the player
	Player* castPlayer = dynamic_cast <Player*>(&_collider);
	Wall* castWall = dynamic_cast<Wall*>(&_collider);
	if (m_active)
	{
		
	// if the player is not nullptr
		if (castPlayer != nullptr)
		{
			// set took damage to true, player loses 45 hp
			// then the bullet will delete itself
			 castPlayer->SetTookDamage(true);
			castPlayer->LoseHealth(45);
			//if (castPlayer->GetHealth <= 100)
			//{
				//castPlayer->Kill()
			//}
			Despawn();
			
		}
		else
		{
			if (castWall != nullptr)
			{
				// delete itself
				Despawn();
			}
		}
	}
}

void Bullet::SetActive(bool _active)
{
	m_active = _active;
}

void Bullet::SetInitialPosition(sf::Vector2f _start)
{
	m_initialPosition = _start;
}

void Bullet::Despawn()
{
	m_active = false;
}