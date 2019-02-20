#pragma once

#include "Obstacle.h"

class Spikes : public Obstacle
{
	Spikes();

	void Collider(GameObject&_collider);

};