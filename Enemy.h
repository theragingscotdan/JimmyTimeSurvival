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
	float m_secondsPassed;
	float m_duration;

private:
	double LinearInterpolate(double x0,	double x1, double y0, double y1, double x);
	sf::Vector2f QuadEaseOut(float time, float duration, sf::Vector2f startingPoint, sf::Vector2f endPoint);

};