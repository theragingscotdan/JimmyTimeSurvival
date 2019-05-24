#pragma once

#include "Enemy.h"

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

	enum State
	{
		STATE_BLIND,
		STATE_VISION,
		STATE_SPOTTED,
		STATE_ALERT
	};

	State m_state;
	void UpdateState(State _state, sf::Time _time);//, Player* _player);

	bool m_hasVision;
	float m_timeTillTransition;
	Player* m_player;
	//sf::Sound m_alarmSound;
	float m_notSpottedTime;
	
	
};

