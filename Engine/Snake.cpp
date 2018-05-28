#include "Snake.h"

int Snake::GetX()
{
	return xGrid;
}

int Snake::GetY()
{
	return yGrid;
}

int Snake::GetLength()
{
	return length;
}

bool Snake::GetVel()
{
	return vel;
}

void Snake::AddLength(int x)
{
	length = length + x;
}



void Snake::iniSnake()
{
	xGrid = xStart;
	yGrid = yStart;
	vel = false;
	inhibitW = false;
	inhibitS = false;
	inhibitA = false;
	inhibitD = false;
	inhibitSpace = false;
	length = BeginSnakeLife;
}

void Snake::steering(Keyboard& kbd)
{
	if (kbd.KeyIsPressed('W') && dSnake != D_DOWN && inhibitW == false)
	{
		dSnake = D_UP;
		vel = true;
		inhibitW = true;
	}
	else
		inhibitW = false;

	if (kbd.KeyIsPressed('S') && dSnake != D_UP && inhibitS == false)
	{
		dSnake = D_DOWN;
		vel = true;
		inhibitS = true;
	}
	else
		inhibitS = false;

	if (kbd.KeyIsPressed('A') && dSnake != D_RIGHT && inhibitA == false)
	{
		dSnake = D_LEFT;
		vel = true;
		inhibitA = true;
	}
	else
		inhibitA = false;
	if (kbd.KeyIsPressed('D') && dSnake != D_LEFT && inhibitD == false)
	{
		dSnake = D_RIGHT;
		vel = true;
		inhibitD = true;
	}
	else
		inhibitD = false;
}

void Snake::move()
{
	if (vel == true)
	{
		switch (dSnake)
		{
		case D_DOWN:
			yGrid = yGrid + 1;
			break;
		case D_UP:
			yGrid = yGrid - 1;
			break;
		case D_LEFT:
			xGrid = (xGrid - 1);
			break;
		case D_RIGHT:
			xGrid = xGrid + 1;
			break;
		}
	}
}

