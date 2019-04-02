#pragma once

#include "Enemy.h"


class Rusher : public Enemy
{

public:
	Rusher();
	
	void Update(sf::Time _frameTime);
	void Collide(GameObject& _collider);

private:
	bool m_Charge;

};
