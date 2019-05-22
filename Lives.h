#pragma once

#include "Framework/TextObject.h"
#include "Player.h"

class Lives
	: public TextObject
{
public:
	Lives();

	// overriding methods
	virtual void Update(sf::Time _frameTime);

	// public health methods
	void SetPlayer(Player* _player);


private:
	Player* m_player;


};