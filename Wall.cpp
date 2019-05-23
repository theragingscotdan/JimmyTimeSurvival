#include "Wall.h"
#include "Framework/AssetManager.h"


Wall::Wall()
: SpriteObject()
 , m_level(nullptr)
{
	//Level* level;
	//if (m_level->GetLevel())
	m_sprite.setTexture(AssetManager::GetTexture("graphics/wallPlacehold.png"));
}