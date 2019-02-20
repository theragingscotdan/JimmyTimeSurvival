#include "Fire.h"
#include "Framework/AssetManager.h"

Fire::Fire()
	: Obstacle()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/firePlaceHold.png"));
}