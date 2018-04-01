//
//  Rules.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 4/1/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//
#include "Output.hpp"
#include "Input.hpp"
#include "Scene.hpp"
#include "Constants.hpp"
#include "Button.hpp"
#ifndef Rules_hpp
#define Rules_hpp
class Rules:public Scene{
public:
    Rules(Output* o, Input* i);
    ~Rules();
    
    void load();
    void handleEvent(EventType e);
    void update();
    void render();
    
    bool isActive();
    
private:
    Output *output;
    Input * input;
    
   
    bool active;
    Button* homeButton;
    
};

#endif /* Rules_hpp */


