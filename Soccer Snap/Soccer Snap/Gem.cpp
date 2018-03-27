//
//  Gem.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/21/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Gem.hpp"
static int fieldX = 277;
static int fieldY = 100;
static float velocity = 3.7;


#pragma mark Initialization:
Gem::~Gem(){
    
}

void Gem::setSprite(char* countryName){
    spriteName = countryName;
}

void Gem::load(Output*output, int w, int h){
    outputFacade = output;
    width = w;
    height = h;
    goingToPosition = false;
    goingToFirstStop = false;
}

void Gem::setPos(int gridX, int gridY){
    x = fieldX+gridX*(width);
    y = fieldY+gridY*(width);
    finalX = x;
    finalY = y;
    boardX = gridX;
    boardY = gridY;
}

void Gem::setInitialAnimationPosition(){
    goingToFirstStop = true;
    firstStopY = 329;
    y = firstStopY;
    if(boardX<4){
        firstStopX = 159;
        x = 52 - boardY*(width) - boardX*(4*width);
    }
    else{
        firstStopX = 860;
        x = 967 + boardY*(width) + abs((boardX-7))*(4*width);
    }
    float xDist = finalX - firstStopX;
    float yDist = finalY - firstStopY;
    float alpha = atanf(yDist/xDist);
    xVector = velocity*cosf(alpha);
    yVector = velocity*sinf(alpha);
    if(boardX>=4){
        xVector *=-1;
        yVector *=-1;
    }
    
}

#pragma mark Game Cycle:

void Gem::render(){
    outputFacade->addSprite(spriteName, x, y, width, height);
}

void Gem::update(){
    if(goingToFirstStop){
        if(boardX<4){
            x += velocity;
            if(x >= firstStopX){
                goingToFirstStop = false;
                goingToPosition = true;
            }
        }
        else{
            x -= velocity;
            if(x <= firstStopX){
                goingToFirstStop = false;
                goingToPosition = true;
            }
        }
    }
    else if(goingToPosition){
        x += xVector;
        y += yVector;
        if(fabsf(finalX-x) < velocity && fabsf(finalY-y)<velocity){
            x = finalX;
            y = finalY;
            goingToPosition = false;
            
        }
    }
}
void Gem::clean(){
    
}

#pragma mark Animations:


