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

Gem::Gem(string name){
    spriteName = name;
}


void Gem::load(Output*output){
    outputFacade = output;
    width = Constants::FIELD_WIDTH/Constants::GEMS_PER_ROW;
    selected = false;
    willBeDeleted = false;
    moving = false;
    goingToFirstStop = false;
}

#pragma mark Direction and Position:

void Gem::setPos(int gridX, int gridY){
    x = fieldX+gridX*(width);
    y = fieldY+gridY*(width);
    boardX = gridX;
    boardY = gridY;
}

void Gem::setNewDirection(int gridX, int gridY){
    moving = true;
    finalX = fieldX+gridX*(width);
    finalY = fieldY+gridY*(width);
    float xDist = fieldX+boardX*(width) - x;
    float yDist = fieldY+boardY*(width) - y;
    float distance = sqrtf(xDist*xDist + yDist*yDist);
    xVector = velocity * xDist / distance;
    yVector = velocity * yDist / distance;
}

void Gem::setInitialAnimationPosition(){
    moving = true;
    finalY = 329;
    y = finalY;
    if(boardX<4){
        finalX = 159;
        x = 52 - boardY*(width) - boardX*(4*width);
    }
    else{
        finalX = 860;
        x = 967 + boardY*(width) + abs((boardX-7))*(4*width);
    }
    float xDist = fieldX+boardX*(width) - x;
    float yDist = 0;
    float distance = sqrtf(xDist*xDist + yDist*yDist);
    xVector = velocity * xDist / distance;
    yVector = velocity * yDist / distance;
    goingToFirstStop = true;
    
}

void Gem::setNextPos(int gridY){
    boardY = gridY;
    setNewDirection(boardX, boardY);
}

#pragma mark Game Cycle:

void Gem::render(){
    if(willBeDeleted){
        //hacer algo antes
        //willBeDeleted = false;
    }
    if(selected){
        string name = "Selected";
        string minuteName = spriteName+name;
        outputFacade->addSprite(minuteName, x, y, width);
    }
    else{
        outputFacade->addSprite(spriteName, x, y, width);
    }
}

void Gem::update(){
    if(moving){
        x += xVector;
        y += yVector;
        if(fabsf(finalX-x) < velocity && fabsf(finalY-y)<velocity){
            x = finalX;
            y = finalY;
            moving = false;
            if(goingToFirstStop){
                goingToFirstStop = false;
                setNewDirection(boardX, boardY);
            }
            
        }
    }
    else if(willBeDeleted){
        willBeDeleted = false;
    }

}


#pragma mark Game Logic:

void Gem::switchWithGem(int gridX,int gridY){
    boardX = gridX;
    boardY = gridY;
    setNewDirection(gridX, gridY);
}

bool Gem::hasMouseInside(Point mousePosition){
    if( mousePosition.x < x || mousePosition.x > x + width ||mousePosition.y < y||mousePosition.y > y + width)
    {
        return false;
    }
    return true;
}

void Gem::setDeleted(){
    willBeDeleted = true;
}

bool Gem::needsDelete(){
    return willBeDeleted;
}


bool Gem::isMoving(){
    return moving;
}

bool Gem::isSelected(){
    return selected;
}

void Gem::setSelected(bool isSelected){
    selected = isSelected;
}

string Gem::getType(){
    return spriteName;
}
