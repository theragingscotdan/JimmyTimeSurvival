#include "Bullet.h"
#include "Player.h"
#include "Framework/AssetManager.h"

#define SPEED 300f;

Bullet::Bullet()
	: MovingObject()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/bullet.png"));
}

void Bullet::Update(sf::Time _frameTime)
{
	if (m_active)
	{

	}

}

void Bullet::Collide(GameObject& _collider)
{
	Player* castPlayer = dynamic_cast <Player*>(&_collider);
}