#pragma once

#include "MovingObject.h"
#include "Level.h"
#include <SFML/Audio.hpp>

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
	void SetCanAttack(bool _attack);

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
	sf::Sound m_attackSound;
	sf::Sound m_destroyed;
	sf::Sound m_burning;
	sf::Sound m_open;
	sf::Vector2f m_oldPosition;
	int m_currentHP;
	int m_keys;
	bool m_playing;
	


	void Kill();

	void Attack(sf::Event _gameEvent);

	void AttemptAttack();
		
};