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



protected:
	Player* m_player;

private:
	Level* m_level;
};