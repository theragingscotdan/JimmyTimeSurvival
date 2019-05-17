#pragma once

#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"

class Level;

class Shooter : public Enemy 
{
public:
		Shooter();
		void Update(sf::Time _frameTime);
		virtual void Collide(GameObject& _collider);
		void SetStartPosition(sf::Vector2f _start);
		void SetLevel(Level* _level);

private:
	//Player* m_player;
	float m_secondsPerShoot;
	bool m_shoot;
	bool GetShoot();
	//Bullet* m_bullet;
	sf::Vector2f m_startPosition;
	Level* m_level;
	
};
