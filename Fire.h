#pragma once

#include "Obstacle.h"
#include "Player.h"

class Fire : public Obstacle
{

public:
	Fire();

	void Update(sf::Time _frameTime);
	bool GetStand();
	void SetStand(bool _stand);
	bool GetCanDamage();
	void SetCanDamage(bool _damage);

protected:

private:
	float m_secondsPerStand;
	bool m_stand;

	Player* m_player;
	bool m_canDamage;

};