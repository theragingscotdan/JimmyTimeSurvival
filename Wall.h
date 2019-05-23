#pragma once

#include "Framework/SpriteObject.h"

// library includes
#include <SFML/Graphics.hpp>
class Level;

class Wall : public SpriteObject
{
public:
	Wall();

private:
	Level* m_level;
};