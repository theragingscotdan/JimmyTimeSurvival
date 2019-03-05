#pragma once

#include "MovingObject.h"
#include "Level.h"

class Player : public MovingObject
{
public:
	Player();

	// overriding methods
	void Update(sf::Time _frameTime);
	virtual void Collide(GameObject& _collider);

	void setLevel(Level* _newLevel);
	int GetHealth();
	


protected:

private:
	Level* m_level;
	int m_health;
	bool m_stand;


	int Health();
};