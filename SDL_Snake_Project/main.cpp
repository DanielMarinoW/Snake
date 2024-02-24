#include"Game.h"
#include <iostream>



int main(int argc, char* argv[]) {
    Game b;
    if (!b.initSDL()) {
        cout << "Failed to initialize SDL." << endl;
        return -1;
    }
   
    b.initGame();
   // b.loadAndPlaySound();
    
    while (b.getIsRunning()) {
        b.handleEvent();
        b.moveSnake();
        b.render();
        SDL_Delay(100); 
        b.snakeDie();
        b.snakeDieInWall();
        b.ttf_init();
        
    }

    b.closeSDL();
    return 0;
}