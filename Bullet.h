#pragma once

#include "MovingObject.h"


class Bullet : public MovingObject
{
public:
	Bullet();

	void Update(sf::Time _frameTime);
	virtual void Collide(GameObject& _collider);
	void SetActive(bool _active);
	void SetStartPosition(sf::Vector2f _start);
	 
private:
	sf::Vector2f m_bulletSpawn;
	//sf::Vector
	float m_firedTime;
	float m_distanceTravelled;
	

	void Despawn();
	
};