#include "Background.h"
#include "Framework/AssetManager.h"

Background::Background()
	: SpriteObject()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/FutureTile.png"));
}

void Background::CurrentLevel()
{

}