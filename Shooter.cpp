#include "Shooter.h"
#include "Framework/AssetManager.h"

Shooter::Shooter()
	: Enemy()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/snake.png"));
}

// shooters can possibly get away with not being able to move
// i can make them stationary and change it so they rotate 90 degrees every x seconds
// this will change their facing direction and if they see the player within the vision
// semi-circle, shoot towards the player