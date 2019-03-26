#include "Shooter.h"
#include "Framework/AssetManager.h"

Shooter::Shooter()
	: Enemy()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/snake.png"));
}
