#pragma once

#include "Pickup.h"
#include <SFML/Audio.hpp>

class Key : public  Pickup
{
public:
	Key();

private:

	// overriding methods
	virtual void OnPickup(Player& _player);
	int GetKeys();

private:
	int m_keys;
	sf::Sound m_keyCollect;
};