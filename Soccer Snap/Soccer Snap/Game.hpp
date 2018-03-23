//
//  Game.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/21/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include "Output.hpp"
#include "Input.hpp"
#include "Field.hpp"

class Game{
public:
    Game();
    ~Game();
    
    void init();
    void handleEvents();
    void update();
    void render();
    void clean();
    
    bool running(){return isRunning;};
    
    
private:
    bool isRunning;
    Output *output;
    Input * input;
    Field * field;
};
#endif /* Game_hpp */
