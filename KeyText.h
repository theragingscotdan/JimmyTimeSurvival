#pragma once

#include "Framework/TextObject.h"
#include "Player.h"

class KeyText
	: public TextObject
{
public:
	KeyText();

	// overriding methods
	virtual void Update(sf::Time _frameTime);

	// public health methods
	void SetPlayer(Player* _player);


private:
	Player* m_player;
};