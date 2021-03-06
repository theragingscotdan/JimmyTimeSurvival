#pragma once

#include "Enemy.h"


class Rusher : public Enemy
{

public:
	Rusher();
	
	void Update(sf::Time _frameTime);
	void Collide(GameObject& _collider);
	void SetStartPosition(sf::Vector2f _start);
	void SetEndPositon(sf::Vector2f _end);
	
	private:
	sf::Vector2f m_startPoint;
	sf::Vector2f m_endPoint;
	sf::Vector2f m_position;
	bool m_charge;
	

};
