#pragma once

#include "Framework/SpriteObject.h"

class MovingObject : public SpriteObject
{

public:
	MovingObject();

	void Update(sf::Time _frameTime);

private:


protected:

	sf::Vector2f m_velocity;
	sf::Vector2f m_previousPosition;
};