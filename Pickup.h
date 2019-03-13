#pragma once

// project includes
#include "Framework/SpriteObject.h"
#include "Player.h"

class Pickup : public SpriteObject
{
public:

	Pickup();

	// Overriding methds
	void Collide(GameObject& _collider);

private:

	virtual void OnPickup(Player& _player);

};