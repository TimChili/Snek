#pragma once
#include "Graphics.h"
#include "Colors.h"




class Grid
{

public:
	static constexpr int Width = 40;
	static constexpr int Height = 30;
	static constexpr int BlockHeight =14;
	static constexpr int BlockWidth = 16;
	
	void iniGrid();
	bool Edges(int x, int y);
	bool SafeFoodSpawn(int x, int y);
	void SnakePaint(int x, int y, int length);
	void SnakeCycleColor(Color& c);
	void FoodPaint(int x,int y);
	void SpawnObs(const int& x, const int& y);
	void DecaySnake();
	void GrowSnake();
	void DrawGrid(Graphics& gfx);
	bool GetPassable(int x, int y);
	bool GetSnake(int x, int y);


private:
	struct GridBlock
	{
		int xGrid;
		int yGrid;
		int xLoc;
		int yLoc;
		bool passable;
		bool food;
		bool snake;
		int snakelife;
		Color cSwitch;
	};
	GridBlock gBlocks[Width][Height];
	Color cEmpty = (120, 120, 120);
	Color cSnakeHead;
	Color cSnake;
	Color cSnake1;
	Color cSnake2;
	int colorCycle = 1;
	Color cWall = (255, 255, 255);
	Color cFood;
	

};