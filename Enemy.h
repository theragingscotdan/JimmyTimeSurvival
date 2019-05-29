#pragma once

#include "MovingObject.h"
#include "Player.h"

class Enemy : public MovingObject
{
public:
	Enemy();

	void Update(sf::Time _frameTime);

	void Collide(GameObject& _collider);

	void SetActive(bool _active);

	
protected:
	//Player* m_player;
	bool m_dead;
	bool m_playerSeen;
	float m_secondsPassed;
	float m_duration;
	sf::Vector2f m_modifier;
	
	sf::Vector2f QuadEaseOut(float time, float duration, sf::Vector2f startingPoint, sf::Vector2f endPoint);
	
	

};