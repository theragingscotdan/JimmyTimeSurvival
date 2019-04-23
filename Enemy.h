#pragma once

#include "MovingObject.h"
#include "Player.h"

class Enemy : public MovingObject
{
public:
	Enemy();

	void Update(sf::Time _frameTime);

	void Collide(GameObject& _collider);

	void SetActive(bool _active);

	void Vision(sf::Vector2f);

	sf::Vector2f DistanceFromPlayer(sf::Vector2f);

protected:
	Player* m_player;
	bool m_dead;
	bool m_playerseen;

private:
	double LinearInterpolate(double x0,	double x1, double y0, double y1, double x);

};