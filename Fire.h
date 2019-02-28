#pragma once

#include "Obstacle.h"

class Fire : public Obstacle
{

public:
	Fire();

	void Update(sf::Time _frameTime);
	bool GetStand();
	void SetStand(bool _stand);

protected:

private:
	float m_secondsPerStand;
	bool m_stand;

};