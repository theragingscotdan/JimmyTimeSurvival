#pragma once

#include "Enemy.h"

class Alarmer : public Enemy
{
public:
	Alarmer();

	void Collide(GameObject& _collider);
};

