// project includes
#include "Level.h"

// library includes
#include <iostream>
#include <fstream>

Level::Level()
	: m_currentLevel(0)
{
	LoadLevel(1);
}


void Level::Draw(sf::RenderTarget& _target)
{
	// create and update camera
	sf::View camera = _target.getDefaultView();

	// making the camera follow the player
	//camera.setCenter(m_player->GetPosition());

	// draw game world to the window
	_target.setView(camera);
}

void Level::Update(sf::Time _frameTime)
{

}

void Level::LoadLevel(int _levelToLoad)
{
	// TODO: Clean up level/old level



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
}

void Level::ReloadLevel()
{

}

void Level::LoadNextLevel()
{

}