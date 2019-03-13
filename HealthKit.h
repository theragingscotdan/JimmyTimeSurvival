#pragma once

#include "Player.h"
#include "Pickup.h"


class HealthKit : public  Pickup
{
public:
	HealthKit();

private:

	// overriding methods
	virtual void OnPickup(Player& _player);
};