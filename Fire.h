#pragma once

#include "Obstacle.h"
#include "Player.h"

class Fire : public Obstacle
{

public:
	Fire();

	void Update(sf::Time _frameTime);
	bool GetCanDamage();
	void SetCanDamage(bool _damage);

protected:

private:
	float m_secondsPerStand;
	

	Player* m_player;
	bool m_canDamage;

};