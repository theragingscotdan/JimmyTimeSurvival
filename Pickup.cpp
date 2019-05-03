// project includes
#include "Pickup.h"
#include "Player.h"

Pickup::Pickup()
	:SpriteObject()
{

}

void Pickup::Collide(GameObject& _collider)
{
	// only do something if the thing we touched is the player

	// we take the generic reference to a game object passed in
	// we get the address for that game object
	// we attempt to treat that address as if it is for a player
	// if successful, it IS a player and address is stored n castPlayer
	// if not successful. it is NOT a player and nullptr is stored in castPlayer
	Player* castPlayer = dynamic_cast <Player*>(&_collider);

	// only do the thing if player is not null
	if (castPlayer != nullptr)
	{
		// do something based on type of pickup
		OnPickup(*castPlayer);

		

	}
	//m_active = false;

}

void Pickup::OnPickup(Player& _player)
{
	// do nothing
}