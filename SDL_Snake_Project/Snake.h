#pragma once
#include<SDL.h>
#include<vector>
#include<iostream>
using namespace std;

enum  Direction { UP, DOWN, LEFT, RIGHT,  };

class Snake 
{
public:
	
	vector<SDL_Rect> segmentOfSnake;
	Direction direction;
};

