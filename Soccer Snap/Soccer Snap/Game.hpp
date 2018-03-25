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
#include "Tools.hpp"
#include "Point.hpp"

enum ScreenComponent{
    Canvas,
    Home,
    Pause,
    Other
};

class Game{
public:
    Game();
    ~Game();
    
    void init();
    void run();
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
    
    void homeUp();
    void homeDown();
    void pauseUp();
    void pauseDown();
    
    
    ScreenComponent getClickedArea(Point p);
};

#endif /* Game_hpp */
