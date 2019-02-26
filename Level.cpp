// project includes
#include "Level.h"
#include "Player.h"
#include "Wall.h"

// library includes
#include <iostream>
#include <fstream>

Level::Level()
	: m_currentLevel(0)
	, m_player(nullptr)
	, m_updateList()
	, m_drawListWorld()
	, m_collisionList()
{
	LoadLevel(1);
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
}

void Level::LoadLevel(int _levelToLoad)
{
	// TODO: Clean up level/old level

	// delete any data already in the level
	for (int i = 0; i < m_updateList.size(); ++i)
	{
		delete m_updateList[i];
	}

	// clear out our lists
	m_updateList.clear();
	m_drawListWorld.clear();
	//m_drawListUI.clear();
	//m_collisionList.clear();

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
	const float X_SPACE = 100.0f;
	const float Y_SPACE = 100.0f;

	// create the player first as other objects will need to reference it
	Player* player = new Player();
	m_player = player;

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
}


void Level::ReloadLevel()
{

}

void Level::LoadNextLevel()
{

}