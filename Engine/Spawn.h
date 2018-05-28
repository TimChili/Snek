#pragma once
#include <random>
#include "grid.h"

class Spawn 
{
public:
	Spawn();
	std::random_device(rd);
	std::mt19937(rng);
	std::uniform_int_distribution<int> Distx;
	std::uniform_int_distribution<int> Disty;
	void randomSpawn();
	int getX();
	int getY();

private:
	int x;
	int y;
};