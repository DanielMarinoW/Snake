#pragma once
#include"Snake.h"
#include<SDL.h>
#include<SDL_ttf.h>
#include<iostream>
#include<string>
using namespace std;

static constexpr int SCREEN_WIDTH = 800;
static constexpr int SCREEN_HEIGHT = 600;
static constexpr int BLOCK_SIZE = 20;
static constexpr int INITIAL_LENGTH = 10;

using namespace std;

class Game
{
public:
	 bool initSDL();
	 void closeSDL();
	 void initGame();
	 void handleEvent();
	 void moveSnake();
	 void render();
	 bool getIsRunning();
	 void snakeDieInWall();
	 void snakeDie();
	 bool ttf_init();

private:
	SDL_Texture* textTextureFont1;
	SDL_Texture* textTextureFont2;
	SDL_Rect dRectFont1;
	SDL_Rect dRectFont2;
	SDL_Rect food;
	Snake snake;
	SDL_Rect newHead;
	SDL_Window* gWindow = nullptr;
	SDL_Renderer* gRenderer = nullptr;
	
	int point ;
	bool gRunning = true;
};

