// project includes
#include "Level.h"
#include "Player.h"
#include "Wall.h"
#include "Fire.h"
#include "Spikes.h"
#include "Health.h"
#include "HealthKit.h"
#include "Exit.h"
#include "Toolbox.h"
#include "Shooter.h"
#include "Rusher.h"
#include "Alarmer.h"
#include "Key.h"
#include "ExitLvl2.h"
#include "ExitLvl3.h"
#include "Bullet.h"
#include "Door.h"
#include "KeyText.h"

// library includes
#include <iostream>
#include <fstream>

Level::Level()
	: m_currentLevel(0)
	, m_player(nullptr)
	, m_updateList()
	, m_drawListWorld()
	, m_collisionList()
	, m_drawListUI()
	, m_pendingLevel(0)
{
	LoadLevel(4);
}


void Level::Draw(sf::RenderTarget& _target)
{
	// create and update camera
	sf::View camera = _target.getDefaultView();

	// making the camera follow the player
	camera.setCenter(m_player->GetPosition());

	// draw game world to the window
	_target.setView(camera);

	for (int i = 0; i < m_drawListWorld.size(); ++i)
	{
		if (m_drawListWorld[i]->IsActive())
			m_drawListWorld[i]->Draw(_target);
	}

	// Draw UI to the window
	_target.setView(_target.getDefaultView());
	//Draw UI objects
	for (int i = 0; i < m_drawListUI.size(); ++i)
	{
		if (m_drawListUI[i]->IsActive())
			m_drawListUI[i]->Draw(_target);
	}
}

void Level::Update(sf::Time _frameTime)
{
	// Update all game objects
	for (int i = 0; i < m_updateList.size(); ++i)
	{
		if (m_updateList[i]->IsActive())
			m_updateList[i]->Update(_frameTime);
	}

	// collision detection
	for (int i = 0; i < m_collisionList.size(); ++i)
	{
		GameObject* handler = m_collisionList[i].first;
		GameObject* collider = m_collisionList[i].second;

		if (handler->IsActive() && collider->IsActive())
		{
			if (handler->GetBounds().intersects(collider->GetBounds()))
			{
				handler->Collide(*collider);
			}
		}
	} 
	// IF there is a pending level waiting... 
	if (m_pendingLevel != 0)
	{
		// load it
		LoadLevel(m_pendingLevel);
		// remove pending level
		m_pendingLevel = 0;
	}
}

void Level::LoadLevel(int _levelToLoad)
{
	int currentHealth = 0;
	// TODO: Clean up level/old level
	if (m_player != nullptr)
	{
		currentHealth = m_player->GetHealth();

	}
	// delete any data already in the level
	for (int i = 0; i < m_updateList.size(); ++i)
	{
		delete m_updateList[i];
	}

	// clear out our lists
	m_updateList.clear();
	m_drawListWorld.clear();
	m_drawListUI.clear();
	m_collisionList.clear();

	// set the current level
	m_currentLevel = _levelToLoad;

	// set up the new level

	// Open our file for reading
	std::ifstream inFile;
	std::string fileName = "levels/Level" + std::to_string(m_currentLevel) + ".txt";
	inFile.open(fileName);

	// make sure the file was open
	if (!inFile)
	{
		std::cerr << "Unable to open file" + fileName;
		exit(1); // call system to stop program with error
	}

	// set the starting x and y coordinates used to position level objects
	float x = 0.0f;
	float y = 0.0f;

	// Define the spacng we will use for our grid
	const float X_SPACE = 64.0f;
	const float Y_SPACE = 64.0f;

	// create the player first as other objects will need to reference it
	Player* player = new Player();
	m_player = player;

	if (currentHealth > 0)
	{
		m_player->SetHealth(currentHealth);
	}

	// read each character one by one from the file
	char ch;
	// each time, try to read the next character
	// if sucessful, execute body of loop
	// the "noskipws" means our input from file will include
	// the white space (space and new lines)

	while (inFile >> std::noskipws >> ch)
	{
		// perform actions based on what character was read in

		if (ch == ' ')
		{
			x += X_SPACE;
		}
		else if (ch == '\n')
		{
			y += Y_SPACE;
			x = 0;
		}
		else if (ch == 'P')
		{
			player->SetPosition(x, y);
			player->setLevel(this);
			m_updateList.push_back(player);
			m_drawListWorld.push_back(player);
		}
		else if (ch == 'W')
		{
			Wall* walls = new Wall();
			walls->SetPosition(x, y);
			m_updateList.push_back(walls);
			m_drawListWorld.push_back(walls);
			m_collisionList.push_back(std::make_pair(player, walls));
			
		}
		else if (ch == 'S')
		{
			Spikes* spike = new Spikes();
			spike->SetPosition(x, y);
			m_updateList.push_back(spike);
			m_drawListWorld.push_back(spike);
			m_collisionList.push_back(std::make_pair(player, spike));

		}
		else if (ch == 'F')
		{
			Fire* fires = new Fire();
			fires->SetPosition(x, y);
			m_updateList.push_back(fires);
			m_drawListWorld.push_back(fires);
			m_collisionList.push_back(std::make_pair(player, fires));

		} 
		else if (ch == 'H')
		{
			HealthKit* HP = new HealthKit();
			HP->SetPosition(x, y);
			m_updateList.push_back(HP);
			m_drawListWorld.push_back(HP);
			m_collisionList.push_back(std::make_pair(HP, player));

		}
		else if (ch == 'E')
		{
			Exit* exit = new Exit();
			exit->SetPosition(x, y);
			m_updateList.push_back(exit);
			m_drawListWorld.push_back(exit);
			m_collisionList.push_back(std::make_pair(exit, player));

		}
		else if (ch == 'T')
		{
			Toolbox* tool = new Toolbox();
			tool->SetPosition(x, y);
			m_updateList.push_back(tool);
			m_drawListWorld.push_back(tool);
			m_collisionList.push_back(std::make_pair(tool, player));

		}
		else if (ch == 'G')
		{
			Shooter* gun = new Shooter();
			gun->SetLevel(this);
			gun->SetPosition(x, y);
			gun->SetStartPosition(sf::Vector2f (x, y));
			m_updateList.push_back(gun);
			m_drawListWorld.push_back(gun);
			m_collisionList.push_back(std::make_pair(gun, player));
			m_collisionList.push_back(std::make_pair(player, gun));
			//m_collisionList.push_back(std::make_pair(walls, gun));

		}
		else if (ch == 'R')
		{
			Rusher* rush = new Rusher();
			rush->SetPosition(x, y);
			rush->SetStartPosition(sf::Vector2f(x, y));
			//rush->SetEndPositon(sf::Vector2f(x, y));
			m_updateList.push_back(rush);
			m_drawListWorld.push_back(rush);
			m_collisionList.push_back(std::make_pair(rush, player));
			m_collisionList.push_back(std::make_pair(player, rush));
			m_collisionList.push_back(std::make_pair(rush, rush));
			//m_collisionList.push_back(std::make_pair(rush, walls));

		}
		else if (ch == 'A')
		{
			Alarmer* alarm = new Alarmer();
			alarm->SetPosition(x, y);
			alarm->SetStartPosition(sf::Vector2f(x, y));
			m_updateList.push_back(alarm);
			m_drawListWorld.push_back(alarm);
			m_collisionList.push_back(std::make_pair(alarm, player));
			m_collisionList.push_back(std::make_pair(player, alarm));
			
		}
		else if (ch == 'K')
		{
			Key* keycard = new Key();
			keycard->SetPosition(x, y);
			m_updateList.push_back(keycard);
			m_drawListWorld.push_back(keycard);
			m_collisionList.push_back(std::make_pair(keycard, player));

		}
		else if (ch == 'B')
		{
			ExitLvl2* blocked = new ExitLvl2();
			blocked->SetPosition(x, y);
			m_updateList.push_back(blocked);
			m_drawListWorld.push_back(blocked);
			//m_collisionList.push_back(std::make_pair(blocked, player));
			m_collisionList.push_back(std::make_pair(player, blocked));

		}
		else if (ch == 'L')
		{
		ExitLvl3* denied = new ExitLvl3();
		denied->SetPosition(x, y);
		m_updateList.push_back(denied);
		m_drawListWorld.push_back(denied);
		//m_collisionList.push_back(std::make_pair(blocked, player));
		m_collisionList.push_back(std::make_pair(player, denied));

		}
		else if (ch == 'D')
		{
		Door* door = new Door();
		door->SetPosition(x, y);
		m_updateList.push_back(door);
		m_drawListWorld.push_back(door);
		//m_collisionList.push_back(std::make_pair(blocked, player));
		m_collisionList.push_back(std::make_pair(player, door));

		}

		else if (ch == '-')
		{
			// do no - empty space
		}
		else
		{
			std::cerr << "Unrecognised character in level file: " << ch;
		}
	}
	// close the file now that we are done with it
	inFile.close();

	// score - position not dependant on level
	Health* health = new Health();
	health->SetPlayer(player);
	m_updateList.push_back(health);
	m_drawListUI.push_back(health);

	KeyText* key = new KeyText();
	key->SetPlayer(player);
	m_updateList.push_back(key);
	m_drawListUI.push_back(key);

	
	

		
	


}


void Level::ReloadLevel()
{
	m_pendingLevel = m_currentLevel;
	LoadLevel(m_pendingLevel);
}

void Level::LoadNextLevel()
{
	m_pendingLevel = m_currentLevel + 1;
	LoadLevel(m_pendingLevel);
}

int Level::GetLevel()
{
	return m_currentLevel;
}

void Level::AddObject(GameObject* _object)
{
	m_drawListWorld.push_back(_object);
	m_updateList.push_back(_object);
	m_collisionList.push_back(std::make_pair(_object, m_player));
}