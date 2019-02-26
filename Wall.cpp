#include "Wall.h"
#include "Framework/AssetManager.h"


Wall::Wall()
: SpriteObject()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/wallPlacehold.png"));
}