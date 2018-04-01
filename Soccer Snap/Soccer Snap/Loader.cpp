//
//  Loader.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/25/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Loader.hpp"


#pragma mark Initialization:

Loader::Loader(Output* o, Input* i){
    output = o;
    input = i;
    loading = true;
    animating = true;
}

void Loader::load(){
    setPositions();
}

void Loader::setPositions(){
    ballDimensions = output->getSpriteDimensions("LogoBall");
    logoDimensions = output->getSpriteDimensions("Logo");
    
    float combinedWidth = logoDimensions.x*(9.0/8.0);
    float combinedHeight = logoDimensions.y*(48.0/41.0);
    
    logoX = -logoDimensions.x;
    ballX = logoX - ballDimensions.x;
    finalLogoX = Constants::GAME_SCREEN_WIDTH/2 - (combinedWidth/2);
    finalBallX = finalLogoX + Constants::LOGO_BALL_X_PROPORTION * logoDimensions.x;
    
    ballY = Constants::GAME_SCREEN_HEIGHT/2 - combinedHeight/2;
    logoY = ballY + Constants::BALL_LOGO_Y_PROPORTION * ballDimensions.y;
    
    logoXPerSecond = (finalLogoX-logoX)/(Constants::FPS*Constants::LOADER_ANIMATION_SECONDS);
    ballXPerSecond = (finalBallX-ballX)/(Constants::FPS*Constants::LOADER_ANIMATION_SECONDS);
}

#pragma mark Game Cycle:

void Loader::handleEvent(EventType e){
    if(e == EventType::MouseUp){
        loading = false;
    }
}

void Loader::update(){
    if(animating){
        logoX+=logoXPerSecond;
        ballX+=ballXPerSecond;
        ballRotation+=2;
        if(logoX>=finalLogoX && ballX>= finalBallX){
            animating = false;
            timeLeft = Constants::LOADER_WAITING_SECONDS;
        }
    }
    if(!animating){
        timeLeft -= 1/Constants::FPS;
        if(timeLeft<=0)
            loading = false;
    }
    
}

void Loader::render(){
    output->addSprite("LogoBall", ballX, ballY, ballDimensions.x, 0, ballRotation);
    output->addSprite("Logo", logoX, logoY, logoDimensions.x);
}

bool Loader::isActive(){
    return loading;
}

#pragma mark Delete

Loader::~Loader(){
    
}

