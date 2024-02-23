#include "Game.h"




bool Game::initSDL() {
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

   
    Game::gWindow = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (Game::gWindow == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    
    Game::gRenderer = SDL_CreateRenderer(Game::gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (Game::gRenderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    
    SDL_SetRenderDrawColor(Game::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    return true;
}

void Game::closeSDL()
{
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}

 void Game::initGame()
{
    snake.direction = Direction::RIGHT;
    snake.snakes.clear();
    for (int i = INITIAL_LENGTH - 1; i >= 0 ; --i) {
        snake.snakes.push_back({ i * BLOCK_SIZE  , SCREEN_HEIGHT / 2, BLOCK_SIZE, BLOCK_SIZE });
    }
    point = 0;
    newHead = { 0,0,0,0 };
    food = { 500, 500, BLOCK_SIZE, BLOCK_SIZE };
}

void Game::handleEvent()
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            gRunning = false;
        }
        else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
            case SDLK_UP:
                if (snake.direction != Direction::DOWN) {
                    snake.direction = Direction::UP;
                }
                break;
            case SDLK_DOWN:
                if (snake.direction != Direction::UP) {
                    snake.direction = Direction::DOWN;
                }
                break;
            case SDLK_LEFT:
                if (snake.direction != Direction::RIGHT) {
                    snake.direction = Direction::LEFT;
                }
                break;
            case SDLK_RIGHT:
                if (snake.direction != Direction::LEFT) {
                    snake.direction = Direction::RIGHT;
                }
                break;
            default:
                break;
            }
        }
    }
}

void Game::moveSnake()
{
    
    newHead = snake.snakes.front();
    

    
    switch (snake.direction) {
    case Direction::UP:
        newHead.y -= BLOCK_SIZE;
        break;
    case Direction::DOWN:
        newHead.y += BLOCK_SIZE;
        break;
    case Direction::LEFT:
        newHead.x -= BLOCK_SIZE;
        break;
    case Direction::RIGHT:
        newHead.x += BLOCK_SIZE;
        break;
    }

    snake.snakes.insert(snake.snakes.begin(), newHead);

    if (newHead.x == food.x && newHead.y == food.y) {

        point ++;
      
        food.x = rand() % (SCREEN_WIDTH / BLOCK_SIZE) * BLOCK_SIZE;
        food.y = rand() % (SCREEN_HEIGHT / BLOCK_SIZE) * BLOCK_SIZE;
    }
    else {
        
        snake.snakes.pop_back();
    }
}



void Game::render()
{
    
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    SDL_RenderClear(gRenderer);

    
    SDL_SetRenderDrawColor(gRenderer, 255, 0, 255, 255); 
    for (const auto& segment : snake.snakes) {
        SDL_RenderFillRect(gRenderer, &segment);

        SDL_SetRenderDrawColor(gRenderer, 0, 255,0, 255);
    }
   
    SDL_RenderCopy(gRenderer, textTextureFont1, NULL, &dRectFont1);

    SDL_RenderCopy(gRenderer, textTextureFont2, NULL, &dRectFont2);

    SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255); 
    SDL_RenderFillRect(gRenderer, &food);

    
    SDL_RenderPresent(gRenderer);
}


bool Game::ttf_init()
{
    if (TTF_Init() == -1) {
        return false;
    }
    TTF_Font* font1 = TTF_OpenFont("fonts/Arc.ttf", 24);
    


    if ( font1 == NULL) {
        return false;
    }
    SDL_Surface* tempSurfaceText = NULL;
    SDL_Surface* tempScoreText = NULL;

    tempScoreText = TTF_RenderText_Blended(font1,std::to_string(point).c_str(), {255,255,255,255});
    tempSurfaceText = TTF_RenderText_Blended(font1, "Score: ", { 255,255,255,255 });

    textTextureFont1 = SDL_CreateTextureFromSurface(gRenderer, tempSurfaceText);
    textTextureFont2 = SDL_CreateTextureFromSurface(gRenderer, tempScoreText);
    

    int tw, th, tt, ww;
    SDL_QueryTexture(textTextureFont1, 0, 0, &tw, &th);
    dRectFont1 = { 5,5,tw,th };

    SDL_QueryTexture(textTextureFont2, 0, 0, &tt, &ww);
    dRectFont2 = { 100,5,tt,ww };

    SDL_FreeSurface(tempScoreText);
    SDL_FreeSurface(tempSurfaceText);
    TTF_CloseFont(font1);
    
}



bool Game::getIsRunning()
{
    return gRunning;
}



void Game::snakeDieInWall()
{
     
    

    if (newHead.x < 0 || newHead.y < 0 || newHead.x + BLOCK_SIZE >= SCREEN_WIDTH || newHead.y + BLOCK_SIZE >= SCREEN_HEIGHT) {

        initGame();
    }
    

}

void Game::snakeDie()
{
     

    for (int i = 1 ; i < snake.snakes.size(); i++) {
        if (newHead.x  == snake.snakes.at(i).x && newHead.y == snake.snakes.at(i).y) {
            cout << newHead.x << " " << snake.snakes.at(i).x << " " << i << endl;
            initGame();
            
        }
    }
}





