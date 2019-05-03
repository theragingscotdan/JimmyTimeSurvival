#pragma once

#include "MovingObject.h"


class Bullet : MovingObject
{
public:
	Bullet();

	void Update(sf::Time _frameTime);
	virtual void Collide(GameObject& _collider);

	 
private:
	sf::Vector2f m_bullet;
	
};