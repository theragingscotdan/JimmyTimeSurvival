#pragma once

#include "Enemy.h"
#include "Player.h"


class Shooter : public Enemy 
{
public:
		Shooter();
		void Update(sf::Time _frameTime);
		virtual void Collide(GameObject& _collider);

private:
	//Player* m_player;
	int m_secondsPerShoot;
};
