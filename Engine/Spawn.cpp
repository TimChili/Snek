#include "Spawn.h"
#include "Grid.h"

Spawn::Spawn()
	:
	rng(rd()),
	Distx(0,Grid::Width),
	Disty(0,Grid::Height)
{
}
void Spawn::randomSpawn()
{
	x = Distx(rng);
	y = Disty(rng);
}
int Spawn::getX()
{
	return x;
}
int Spawn::getY()
{
	return y;
}
;
