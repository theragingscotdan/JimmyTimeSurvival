#pragma once
#include "Framework/SpriteObject.h"
#include "Player.h"

//library includes
#include <SFML/Graphics.hpp>

class Exit
	: public SpriteObject

{
public:
	Exit();

	// overriding methods
	virtual void Update(sf::Time _frameTime);
	void Collide(GameObject& _collider);

	//public exit methods
	void SetPlayer(Player* _player);
	void SetLevel(Level* _level);


private:
	Player* m_player;
	Level* m_level;
};