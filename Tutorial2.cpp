#include "Tutorial2.h"
#include "Framework/AssetManager.h"

Tutorial2::Tutorial2()
	: SpriteObject()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/tutorialLvl2.png"));
}