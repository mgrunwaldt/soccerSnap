//
//  main.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/21/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include <iostream>
#include "Game.hpp"

Game * game = nullptr;
int main(int argc, const char * argv[]) {
    game = new Game();
    game->init();
    game->run();
   }
