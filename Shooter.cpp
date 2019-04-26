#include "Shooter.h"
#include "Framework/AssetManager.h"

#define DISTANCE 300.0f

Shooter::Shooter()
	: Enemy()
	, m_secondsPerShoot(0)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/snake.png"));
}

// shooters can possibly get away with not being able to move
// i can make them stationary and change it so they rotate 90 degrees every x seconds
// this will change their facing direction and if they see the player within the vision
// semi-circle, shoot towards the player

void Shooter::Update(sf::Time _frameTime)
{
	m_secondsPerShoot += _frameTime.asSeconds();
}

void Shooter::Collide(GameObject& _collider)
{

}