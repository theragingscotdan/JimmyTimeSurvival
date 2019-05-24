#pragma once

// library includes
#include "Framework/GameObject.h"

// project includes

// forward declaration
class Player;

class Level
{

public:
	Level();

	void Draw(sf::RenderTarget& _target);
	void Update(sf::Time _frameTime);

	void LoadLevel(int _levelToLoad, int _totalMilliseconds);
	void ReloadLevel();
	void LoadNextLevel();
	int GetLevel();
	void AddObject(GameObject* _object);

private:

	int m_currentLevel;
	int m_pendingLevel;

	Player* m_player;
	std::vector<GameObject*> m_updateList;
	std::vector<GameObject*> m_drawListWorld;
	std::vector<GameObject*> m_drawListUI;

	std::vector<std::pair<GameObject*, GameObject*>> m_collisionList;

};