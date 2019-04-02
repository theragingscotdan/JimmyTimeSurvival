#pragma once

#include "Enemy.h"


class Rusher : public Enemy
{

public:
	Rusher();
	
	void Update(sf::Time _frameTime);

private:
	bool m_IsCharging;

};
