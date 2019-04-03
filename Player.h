#pragma once

#include "MovingObject.h"
#include "Level.h"

class Player : public MovingObject
{
public:
	Player();

	// overriding methods
	void Update(sf::Time _frameTime);
	virtual void Collide(GameObject& _collider);

	void AddHealth(int _changeBy);
	void LoseHealth(int _changeBy);

	void setLevel(Level* _newLevel);
	int GetHealth();
	void SetHealth(int _health);
	bool GetAttack();


protected:

private:
	Level* m_level;
	int m_health;
	bool m_stand;
	bool m_attack;

	void Kill();

	void Attack(sf::Event _gameEvent);


	int Health();
};