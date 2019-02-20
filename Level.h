#pragma once

// library includes
#include "Framework/GameObject.h"

// project includes


class Level
{

public:
	Level();

	void Draw(sf::RenderTarget& _target);
	void Update(sf::Time _frameTime);

	void LoadLevel(int _levelToLoad);
	void ReloadLevel();
	void LoadNextLevel();


private:

	int m_currentLevel;
	GameObject* m_player;


};