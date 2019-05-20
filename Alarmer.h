#pragma once

#include "Enemy.h"

class Alarmer : public Enemy
{
public:
	Alarmer();

	void Collide(GameObject& _collider);
	void SetStartPosition(sf::Vector2f _start);

private:
	sf::Vector2f m_position;

	enum State
	{
		STATE_PASSIVE,
		STATE_SPOTTED,
		STATE_ALERT
	};

	State m_state;
};

