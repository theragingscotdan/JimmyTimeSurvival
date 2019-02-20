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

protected:

private:
	Level* m_level;

};