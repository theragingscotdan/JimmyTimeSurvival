#include "Shooter.h"
#include "Bullet.h"
#include "Framework/AssetManager.h"

#define DISTANCE 300.0f

Shooter::Shooter()
	: Enemy()
	, m_secondsPerShoot(0.0f)
	, m_shoot(false)
	, m_level(nullptr)
	//, m_bullet(nullptr)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/snake.png"));
}

// shooters can possibly get away with not being able to move
// i can make them stationary and change it so they rotate 90 degrees every x seconds
// this will change their facing direction and if they see the player within the vision
// semi-circle, shoot towards the player - not happening


//  what i will do instead, is every x seconds, the shooter will rotate by 90 degrees
// then fire then rotate etc

void Shooter::Update(sf::Time _frameTime)
{
	
	m_secondsPerShoot += _frameTime.asSeconds();
	if (m_secondsPerShoot > 2.0f)
	{
		m_shoot = true;
		m_sprite.setTexture(AssetManager::GetTexture("graphics/spikesPlacehold"));
		//m_bullet->SetActive(true);
		m_secondsPerShoot = 0.0f;
	}
	else
	{
		m_shoot = false;
		m_sprite.setTexture(AssetManager::GetTexture("graphics/snake.png"));
	} 

	if (m_shoot)
	{
		Bullet* m_bullet = new Bullet();
		if (m_bullet != nullptr)
		{
			//m_bullet = new Bullet();
			m_bullet->SetPosition(this->m_sprite.getPosition());
			m_bullet->SetActive(true);
			//m_bullet->SetStartPosition();
			// add the bullet movement code here. 
			// look up c# from year 1
			//m_bullet->SetActive(true);
			
			//m_velocity

			m_level->AddObject(m_bullet);
		}
	}
}

void Shooter::Collide(GameObject& _collider)
{

}

bool Shooter::GetShoot()
{
	return m_shoot;
} 

void Shooter::SetStartPosition(sf::Vector2f _start)
{
	m_startPosition = _start;
}

void Shooter::SetLevel(Level* _level)
{
	m_level = _level;
}