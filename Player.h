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
	void SetTookDamage(bool _damaged);
	void AdvanceLevel();
	void SetToolkit(bool _hasTool);
	bool GetToolkit();
	int GetKeys();
	void SetKeys(int _keys);

protected:

private:
	Level* m_level;
	int m_health;
	bool m_stand;
	bool m_attack;
	bool m_justAttacked;
	bool m_tookDamage;
	float m_timeSinceDamage;
	bool m_canAttack;
	bool hasToolbox;
	int m_lives;
	sf::Vector2f m_oldPosition;
	int m_currentHP;
	int m_keys;
	

	//bool AttemptBack(sf::Vector2f _direction);

	void Kill();

	void Attack(sf::Event _gameEvent);

	void AttemptAttack();


	int Health();
};