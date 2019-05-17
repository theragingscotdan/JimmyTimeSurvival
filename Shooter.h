#pragma once

#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"


class Shooter : public Enemy 
{
public:
		Shooter();
		void Update(sf::Time _frameTime);
		virtual void Collide(GameObject& _collider);
		void SetStartPosition(sf::Vector2f _start);

private:
	//Player* m_player;
	float m_secondsPerShoot;
	bool m_shoot;
	bool GetShoot();
	//Bullet* m_bullet;
	sf::Vector2f m_startPosition;
	
};
