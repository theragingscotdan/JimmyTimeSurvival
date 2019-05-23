#pragma once

#include "Framework/SpriteObject.h"
#include "Player.h"

class Door
	: public SpriteObject
{

public:
	Door();

	virtual void Update(sf::Time _frameTime);
	void Collide(GameObject&_collider);
	void SetActive(bool _active);


private:
	Player* m_player;
};