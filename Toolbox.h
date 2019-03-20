#pragma once

#include "Player.h"
#include "Pickup.h"


class Toolbox : public  Pickup
{
public:
	Toolbox();

private:

	// overriding methods
	virtual void OnPickup(Player& _player);
};