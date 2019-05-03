#pragma once

#include "Exit.h"
#include "Player.h"

class ExitLvl2 : public Exit
{
public:
	ExitLvl2();

	virtual void Update(sf::Time _frameTime);
	void Collide(GameObject& _collider);

private:

	Player* m_player;
};