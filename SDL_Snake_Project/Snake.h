#pragma once
#include<SDL.h>
#include<vector>
#include<iostream>
using namespace std;

enum class Direction { UP, DOWN, LEFT, RIGHT };

class Snake 
{
public:
	vector<SDL_Rect> snakes;
	Direction direction;
};

