#include"Game.h"
#include <iostream>



int main(int argc, char* argv[]) {
    Game b;

    if (!b.initSDL()) {
        cout << "Failed to initialize SDL." << endl;
        return -1;
    }
   
    
    b.loadAndPlaySound();
    
    while (b.getIsRunning()) {
        b.ttf_init();
        b.handleEvent();
        b.render();
        if (b.startPlay == true) {
            b.moveSnake();
        }
        SDL_Delay(100); 
        b.snakeDie();
        b.snakeDieInWall();
    }
   
    b.closeSDL();
    return 0;
}