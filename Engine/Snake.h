#pragma once
#include "Keyboard.h"


class Snake
{
public:
	int GetX();
	int GetY();
	int GetLength();
	bool GetVel();
	void AddLength(int x);
	void steering(Keyboard& kbd);
	void move();
	void iniSnake();
	static constexpr int BeginSnakeLife = 5;
private:
	int xGrid;
	int yGrid;
	int xStart = 5;
	int yStart = 5;
	int length;
	bool vel;


	enum Direction
	{
		D_UP,
		D_DOWN,
		D_LEFT,
		D_RIGHT
	};
	Direction dSnake;
	bool inhibitW;
	bool inhibitS;
	bool inhibitA;
	bool inhibitD;
	bool inhibitSpace;
};
