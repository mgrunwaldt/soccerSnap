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
}

Timer::~Timer(){

}

void Timer::setPos(int x, int y){

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
    
    string minuteName = name+to_string(minute);
    string tenthMinuteName = name+to_string(tenthMinute);
    string secondName = name+to_string(second);
    string tenthSecondName = name+to_string(tenthSecond);
    
    outputFacade->addSprite(tenthMinuteName, 461, 22, 34);
    outputFacade->addSprite(minuteName, 495, 22, 34);
    outputFacade->addSprite("TimerSeparator", 531, 22, 10);
    outputFacade->addSprite(tenthSecondName, 539, 22, 34);
    outputFacade->addSprite(secondName, 573, 22, 34);
}

#pragma mark Actions:

void Timer::start(){
    active = true;
}

void Timer::stop(){
    active = false;
}

bool Timer::isActive(){
    return active;
}

bool Timer::hasTimeLeft(){
    return secondsLeft>0;
}

void Timer::addTime(int seconds){
    secondsLeft+=seconds;
}

int Timer::getMinutesFromSecondsLeft(){
    return secondsLeft/60;
}

int Timer::getSecondsRemaining(){
    return secondsLeft%60;
}
