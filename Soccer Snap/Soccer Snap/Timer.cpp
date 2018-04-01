//
//  Timer.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/26/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Timer.hpp"

#pragma mark Setup:

Timer::Timer(Output* o, int seconds){
    outputFacade = o;
    secondsLeft = seconds;
    timeLeft = secondsLeft;
    active = false;
    boardSize = outputFacade->getSpriteDimensions("Board");
    separatorSize = outputFacade->getSpriteDimensions("TimerSeparator");
    numberSize = outputFacade->getSpriteDimensions("Timer0");
}


#pragma mark Game Cycle:

void Timer::update(){
    float secondsElapsed = Constants::FRAME_DELAY/1000;
    timeLeft-=secondsElapsed;
    secondsLeft = ceilf(timeLeft);
    if(secondsLeft == 0){
        active = false;
    }
    
    
}

void Timer::render(){
    int minutes = getMinutesFromSecondsLeft();
    int seconds = getSecondsRemaining();
    
    int tenthMinute = minutes / 10 % 10;
    int minute = minutes % 10;
    int tenthSecond = seconds / 10 % 10;
    int second = seconds % 10;
    
    string name = "Timer";
    
    if(secondsLeft<=10){
        name += "Red";
    }
    
    string minuteName = name+to_string(minute);
    string tenthMinuteName = name+to_string(tenthMinute);
    string secondName = name+to_string(second);
    string tenthSecondName = name+to_string(tenthSecond);
    string timerSeparatorName = name+"Separator";
    int timerX = (Constants::GAME_SCREEN_WIDTH-boardSize.x)/2;
    int timerY = Constants::GAME_SCREEN_HEIGHT*0.02;
    
    outputFacade->addSprite("Board", timerX, timerY, boardSize.x);

    
    outputFacade->addSprite(tenthMinuteName,4+timerX, timerY+4, numberSize.x);
    outputFacade->addSprite(minuteName, 4+timerX+numberSize.x, timerY+4, numberSize.x);
    outputFacade->addSprite(timerSeparatorName, 4+timerX+2*numberSize.x, timerY+4, separatorSize.x);
    outputFacade->addSprite(tenthSecondName, 4+timerX+2*numberSize.x+separatorSize.x, timerY+4, numberSize.x);
    outputFacade->addSprite(secondName, 4+timerX+3*numberSize.x+separatorSize.x, timerY+4, numberSize.x);
}

#pragma mark Actions:



bool Timer::hasTimeLeft(){
    return secondsLeft>0;
}

void Timer::addTime(int seconds){
    timeLeft+=seconds;
}

int Timer::getMinutesFromSecondsLeft(){
    return secondsLeft/60;
}

int Timer::getSecondsRemaining(){
    return secondsLeft%60;
}

#pragma mark Destructor:

Timer::~Timer(){
    
}
