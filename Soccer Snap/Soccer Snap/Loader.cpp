//
//  Loader.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/25/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Loader.hpp"

float logoX = -739;
float ballX = -300;
float finalLogoX = 123;
float finalBallX = 773;

float logoXPerSecond;
float ballXPerSecond;

int ballRotation = 0;

Loader::Loader(Output* o, Input* i){
    output = o;
    input = i;
    loading = true;
}

Loader::~Loader(){

}

void Loader::load(){
    logoXPerSecond = (finalLogoX-logoX)/(Constants::FPS*Constants::loaderSeconds);
    ballXPerSecond = (finalBallX-ballX)/(Constants::FPS*Constants::loaderSeconds);
    output->addSprite("LogoBall", ballX, 203, 175, 0, ballRotation);
    output->addSprite("Logo", logoX, 240, 739);
}

void Loader::handleEvents(){
    
}
void Loader::update(){
    logoX+=logoXPerSecond;
    ballX+=ballXPerSecond;
    ballRotation+=2;
    if(logoX>=finalLogoX && ballX>= finalBallX){
        loading = false;
    }
}

void Loader::render(){
    output->clearScreen();
    output->addSprite("LogoBall", ballX, 203, 175, 0, ballRotation);
    output->addSprite("Logo", logoX, 240, 739);

    output->drawScreen();
}

void Loader::clean(){
    
}


bool Loader::isActive(){
    return loading;
}
