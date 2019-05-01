#pragma once

#include "Exit.h"

class Exit1
	: public Exit

{
public:
	Exit1();

	// overriding methods
	virtual void Update(sf::Time _frameTime);
	void Collide(GameObject& _collider);



private:

};