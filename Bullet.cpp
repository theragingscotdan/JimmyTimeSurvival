#include "Bullet.h"
#include "Player.h"
#include "Wall.h"
#include "Framework/AssetManager.h"

#define SPEED 300f;

Bullet::Bullet()
	: MovingObject()
	, m_bullet(0.0f, 0.0f)
	, m_firedTime(0.0f)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/bullet.png"));
}

void Bullet::Update(sf::Time _frameTime)
{
	
	
	if (m_active)
	{
		//m_bullet.
		//m_bullet.
		//m_currentPosition += m_velocity;
		m_firedTime += _frameTime.asSeconds();
		
	}

}

void Bullet::Collide(GameObject& _collider)
{
	
	if (m_active)
	{
		Player* castPlayer = dynamic_cast <Player*>(&_collider);

		if (castPlayer != nullptr)
		{
			castPlayer->LoseHealth(45);
			// then delete itself
			Despawn();
		}

		Wall* castWall = dynamic_cast<Wall*>(&_collider);

		if (castWall != nullptr)
		{
			// delete itself
			Despawn();
		}
	}
}

void Bullet::SetActive(bool _active)
{
	m_active = _active;
}

void Bullet::Despawn()
{
	m_active = false;
}