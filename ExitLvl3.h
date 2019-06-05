#pragma once

#pragma once

#include "Exit.h"
#include "Player.h"

class ExitLvl3 : public Exit
{
public:
	ExitLvl3();

	virtual void Update(sf::Time _frameTime);
	void Collide(GameObject& _collider);
	void SetActive(bool _active);
	void SetPlayer(Player* _player);

private:



};