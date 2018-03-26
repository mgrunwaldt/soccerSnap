//
//  Loader.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/25/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#ifndef Loader_hpp
#define Loader_hpp
#include "Output.hpp"
#include "Input.hpp"
#include "Scene.hpp"
#include "Constants.hpp"

class Loader:public Scene{
public:
    Loader(Output* o, Input* i);
    ~Loader();
    
    
    void load();
    void handleEvents();
    void update();
    void render();
    void clean();
    
    bool isActive();

    
    
private:
    Output *output;
    Input * input;
    bool loading;
};
#endif /* Loader_hpp */
