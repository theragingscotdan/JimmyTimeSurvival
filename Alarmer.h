#pragma once

#include "Enemy.h"
#include <SFML/Audio.hpp>

class Alarmer : public Enemy
{
public:
	Alarmer();

	void Update(sf::Time _frameTime);
	void Collide(GameObject& _collider);
	void SetStartPosition(sf::Vector2f _start);
	void SetPlayer(Player* _player);

private:
	sf::Vector2f m_position;

	void SightTime(sf::Time _frameTime);
	void PlayerLocation(sf::Vector2f playerPos, sf::Vector2f enemyPos);
	void SeenPlayer(sf::Time _frametime);

	// enum used to create the finite state machine
	enum State
	{
		// these are the 4 states
		STATE_BLIND,
		STATE_VISION,
		STATE_SPOTTED,
		STATE_ALERT
	};

	State m_state;
	void UpdateState(State _state, sf::Time _time);

	bool m_hasVision;
	float m_timeTillTransition;
	Player* m_player;
	sf::Sound m_alarmSound;
	float m_SpottedTime;
	
	
};

