#pragma once

#include "MovingObject.h"
#include "Player.h"

class Enemy : public MovingObject
{
public:
	Enemy();

	void Update(sf::Time _frameTime);

private:
	Player* m_player;
};