#include "Grid.h"


void Grid::iniGrid()
{
	//Food Green
	cFood.SetR(21);
	cFood.SetG(216);
	cFood.SetB(76);
	//Snake Yellow
	cSnake.SetR(216);
	cSnake.SetG(180);
	cSnake.SetB(21);
	//Snake Orange
	cSnake1.SetR(217);
	cSnake1.SetG(147);
	cSnake1.SetB(28);
	//Snake Orange
	cSnake2.SetR(153);
	cSnake2.SetG(99);
	cSnake2.SetB(7);
	//Wall White
	cWall.SetR(21);
	cWall.SetG(6);
	cWall.SetB(68);
	//Empty Light Blue
	cEmpty.SetR(57);
	cEmpty.SetG(71);
	cEmpty.SetB(81);
	// SnakeHead
	cSnakeHead.SetR(165);
	cSnakeHead.SetG(18);
	cSnakeHead.SetB(74);
	int xStep = (Graphics::ScreenWidth-80) / Width;
	int yStep = (Graphics::ScreenHeight-60) / Height;
	for (int i = 0; i < Width; i++)
		for (int j = 0; j < Height; j++)
		{
			gBlocks[i][j].xGrid = i;
			gBlocks[i][j].yGrid = j;
			gBlocks[i][j].xLoc = i*xStep;
			gBlocks[i][j].yLoc = j*yStep;
			gBlocks[i][j].passable = Edges(i,j);
			gBlocks[i][j].snakelife = 0;
			gBlocks[i][j].food = false;
			gBlocks[i][j].snake = false;
			if (gBlocks[i][j].passable)
			{
				gBlocks[i][j].cSwitch.SetR(cEmpty.GetR());
				gBlocks[i][j].cSwitch.SetB(cEmpty.GetB());
				gBlocks[i][j].cSwitch.SetG(cEmpty.GetG());
			}
			else
			{
				gBlocks[i][j].cSwitch.SetR(cWall.GetR());
				gBlocks[i][j].cSwitch.SetB(cWall.GetB());
				gBlocks[i][j].cSwitch.SetG(cWall.GetG());
			}
		}

}

bool Grid::Edges(int x, int y)
{
	if (x == 0 || y == 0 || x == Width-1 || y == Height-1)
		return false;
	else
		return true;
}

bool Grid::SafeFoodSpawn(int x, int y)
{
	if (gBlocks[x][y].passable == true && gBlocks[x][y].snake == false && gBlocks[x][y].food == false)
	{
		return true;
	}
	else
		return false;
}

void Grid::SnakePaint(int x, int y, int life)
{
	gBlocks[x][y].snake = true;
	gBlocks[x][y].snakelife = life;
	gBlocks[x][y].cSwitch = cSnakeHead;
}

void Grid::SnakeCycleColor(Color& c) // Shit code, just red spectrum
{
	if (c.GetR() == cSnake.GetR() || c.GetR() == cSnakeHead.GetR())
		c = cSnake1;
	else if (c.GetR() == cSnake1.GetR())
		c = cSnake2;
	else if (c.GetR() == cSnake2.GetR())
		c = cSnake;
}

void Grid::FoodPaint(int x, int y)
{
	gBlocks[x][y].food = true;
	gBlocks[x][y].cSwitch = cFood;
}

void Grid::SpawnObs(const int & x, const int & y)
{
	gBlocks[x][y].passable = false;
	gBlocks[x][y].cSwitch = cWall;
}

void Grid::DecaySnake()
{
	for (int i = 0; i < Width; i++)
		for (int j = 0; j < Height; j++)
		{
			if (gBlocks[i][j].snakelife != 0)
			{
				gBlocks[i][j].snakelife = gBlocks[i][j].snakelife - 1;
				SnakeCycleColor(gBlocks[i][j].cSwitch);
				if (gBlocks[i][j].snakelife == 0)
				{
					gBlocks[i][j].snake = false;
					gBlocks[i][j].cSwitch = cEmpty;
				}
			}
		}
}

void Grid::GrowSnake()
{
	for (int i = 0; i < Width; i++)
		for (int j = 0; j < Height; j++)
		{
			if (gBlocks[i][j].snakelife != 0)
				gBlocks[i][j].snakelife = gBlocks[i][j].snakelife + 1;
		}
			
}

void Grid::DrawGrid(Graphics& gfx)
{
	for (int i = 0; i < Width; i++)
		for (int j = 0; j < Height; j++) 
		{
			int CornerX = gBlocks[i][j].xLoc +40;
			int CornerY = gBlocks[i][j].yLoc +30;
			gfx.DrawRecDim(CornerX, CornerY, BlockWidth, BlockHeight, gBlocks[i][j].cSwitch);
		}
}

bool Grid::GetPassable(int x, int y)
{
	return gBlocks[x][y].passable;
}

bool Grid::GetSnake(int x, int y)
{
	return gBlocks[x][y].snake;
}
			
	
