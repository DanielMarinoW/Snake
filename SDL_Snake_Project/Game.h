#pragma once
#include"Snake.h"
#include<SDL_ttf.h>
#include<iostream>
#include<string>
#include <SDL.h>
#include <SDL_mixer.h>
#include "SoundManager.h"
#include"TextureManager.h"
#include"Button.h"
using namespace std;

static constexpr int SCREEN_WIDTH = 800;
static constexpr int SCREEN_HEIGHT = 600;
static constexpr int BLOCK_SIZE = 20;
static constexpr int INITIAL_LENGTH = 3;

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
	 bool snakeDieInWall();
	 bool snakeDie();
	 bool ttf_init();
	 void loadAndPlaySound();
	 void update();
	 bool startPlay = false;
private:
	Button Info = Button(746,17,783,63, INFO);
	Button Play = Button(237, 233, 565, 364, START);
	SDL_Texture* textTextureFont1;
	SDL_Texture* textTextureFont2;
	SDL_Rect dRectFont1;
	SDL_Rect dRectFont2;
	SDL_Rect food;
	Snake snake;
	SDL_Rect newHead;
	SDL_Window* gWindow = nullptr;
	SDL_Renderer* gRenderer = nullptr;
	bool stopSnake = false;
	bool infoIsClicked;
	int point ;
	bool gRunning = true;
};

