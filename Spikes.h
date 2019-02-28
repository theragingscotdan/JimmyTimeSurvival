#pragma once

#include "Obstacle.h"

class Spikes : public Obstacle
{
public:
	Spikes();

private:
	void Collider(GameObject&_collider);

};