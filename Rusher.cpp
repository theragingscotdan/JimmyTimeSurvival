#include "Rusher.h"
#include "Framework/AssetManager.h"

Rusher::Rusher()
	:Enemy()
	, m_IsCharging(false)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/buffalo.png"));
}

void Rusher::Update(sf::Time _frameTime)
{

}