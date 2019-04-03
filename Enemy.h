#pragma once

#include "MovingObject.h"
#include "Player.h"

class Enemy : public MovingObject
{
public:
	Enemy();

	void Update(sf::Time _frameTime);

	void Collide(GameObject& _collider);

protected:
	Player* m_player;

private:
	double LinearInterpolate(double x0,	double x1, double y0, double y1, double x);
};