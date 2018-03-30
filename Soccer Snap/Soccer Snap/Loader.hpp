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
#include "Tools.hpp"

class Loader:public Scene{
public:
    Loader(Output* o, Input* i);
    ~Loader();
    
    void load();
    void handleEvent(EventType e);
    void update();
    void render();
    
    bool isActive();
    void setPositions();
    
private:
    Output *output;
    Input * input;
    
    Point ballDimensions;
    Point logoDimensions;
    
    bool loading;
    bool animating;
    float timeLeft;
    
    float logoX;
    float logoY;
    float ballX;
    float ballY;
    float finalLogoX;
    float finalBallX;
    
    float logoXPerSecond;
    float ballXPerSecond;
    int ballRotation;

};
#endif /* Loader_hpp */
