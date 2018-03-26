//
//  Timer.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/26/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#ifndef Timer_hpp
#define Timer_hpp

#include "GameObject.hpp"
#include "Output.hpp"
#include "Constants.hpp"
#include <string>

class Timer: public GameObject{
    
public:
    ~Timer();
    Timer(Output*o,int seconds);
    
    void render();
    void update();
    void clean();
    void setPos(int gridX, int gridY);
    
    void start();
    void stop();
    
    bool hasTimeLeft();
    bool isActive();
    
    void addTime(int seconds);
    
private:
    Output* outputFacade;
    float timeLeft;
    int secondsLeft;
    int getMinutesFromSecondsLeft ();
    int getSecondsRemaining();
    bool active;
};
#endif /* Timer_hpp */
