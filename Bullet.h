#pragma once

#include "MovingObject.h"


class Bullet : public MovingObject
{
public:
	Bullet();

	void Update(sf::Time _frameTime);
	virtual void Collide(GameObject& _collider);
	void SetActive(bool _active);

	 
private:
	sf::Vector2f m_bullet;
	//sf::Vector
	float m_firedTime;
	

	void Despawn();
	
};