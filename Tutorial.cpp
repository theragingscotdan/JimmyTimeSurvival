#include "Tutorial.h"
#include "Framework/AssetManager.h"

Tutorial::Tutorial()
	: SpriteObject()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/tutorial1.png"));
}