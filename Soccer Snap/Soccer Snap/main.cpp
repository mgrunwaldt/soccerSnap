//
//  main.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/21/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include <iostream>
#include "Game.hpp"
#include "Tools.hpp"

Game * game = nullptr;
int main(int argc, const char * argv[]) {
    const int FPS = 60;
    const int frameDelay = 1000/FPS;
    
    Uint32 frameStart;
    int frameTime;
    
    game = new Game();
    game->init();
    
    while (game->running()) {
        frameStart = Tools::getTicks();
        
        game->handleEvents();
        game->update();
        game->render();
    
        frameTime = Tools::getTicks()- frameStart;
        
        if(frameDelay>frameTime){
            Tools::delay(frameDelay-frameTime);
        }
    }
    
    game->clean();
    
   }
