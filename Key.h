#pragma once

#include "Pickup.h"

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
};