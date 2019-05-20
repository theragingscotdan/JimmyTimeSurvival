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
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/bullet.png"));
}

void Bullet::Update(sf::Time _frameTime)
{
	//sf::Vector2f m_currentPosition;
	sf::Vector2f m_currentPosition = m_sprite.getPosition();
	//if ()
	if (m_active)
	{
		//m_firedTime += _frameTime.asSeconds();
		//m_bullet.
		//m_bullet.
		
		m_currentPosition += sf::Vector2f(0.0f, 0.5f);

		m_distanceTravelled += 1.0f;
		
		
		//m_newPosition;
		m_sprite.setPosition(m_currentPosition);
		
	}

	MovingObject::Update(_frameTime);
}

void Bullet::Collide(GameObject& _collider)
{
	Player* castPlayer = dynamic_cast <Player*>(&_collider);
	Wall* castWall = dynamic_cast<Wall*>(&_collider);
	if (m_active)
	{
		

		if (castPlayer != nullptr)
		{
			// then delete itself
			Despawn();
			castPlayer->SetTookDamage(true);
			castPlayer->LoseHealth(45);
			
			
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

void Bullet::SetStartPosition(sf::Vector2f _start)
{
	//m_currentPosition = _start;
}

void Bullet::Despawn()
{
	m_active = false;
}