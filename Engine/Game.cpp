/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"


Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	Gameboard.iniGrid();
	Player.iniSnake();
	SpawnFood(Food);
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	Player.steering(wnd.kbd);
	if (gametick >= resolution)
	{
		Player.move();
		Gameboard.DecaySnake();
		Collide();
		Eat();
		Gameboard.SnakePaint(Player.GetX(), Player.GetY(), Player.GetLength());
		gametick = 0;
	}
	else
		gametick = gametick + tickspeed;
}

void Game::ComposeFrame()
{
	Gameboard.DrawGrid(gfx);
}

void Game::Collide()
{
	int x = Player.GetX();
	int y = Player.GetY();
	if (Gameboard.GetPassable(x, y) == false || Gameboard.GetSnake(x, y) == true)
	{ 
		if (Player.GetVel () == true) 
		{
			Gameboard.iniGrid();
			Player.iniSnake();
			SpawnFood(Food);
			tickspeed = 20;
		}
	}
}

void Game::SpawnFood(Spawn& Food)
{
	bool spawn = false;
	while (spawn == false)
	{
		Food.randomSpawn();
		spawn = Gameboard.SafeFoodSpawn(Food.getX(), Food.getY());
	}
	Gameboard.FoodPaint(Food.getX(), Food.getY());
}

void Game::SpawnObstacle(Spawn & Obst)
{
	do
		Obst.randomSpawn();
	while (Gameboard.SafeFoodSpawn(Obst.getX(), Obst.getY()) == false);
	Gameboard.SpawnObs(Obst.getX(), Obst.getY());
}

void Game::Eat()
{
	if (Player.GetX() == Food.getX() && Player.GetY() == Food.getY())
	{
		Player.AddLength(1);
		Gameboard.GrowSnake();
		SpawnFood(Food);
		SpawnObstacle(Obstacle);
		if (tickspeed < resolution)
			tickspeed = tickspeed + 2;
	}
}

