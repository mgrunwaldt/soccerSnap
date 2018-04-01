//
//  Gem.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/21/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Gem.hpp"
int fieldX;
int fieldY;
int fieldWidth;

const int PLAYER_VALUES [3] = {15,20,25};
const int OPPONENT_VALUES [3] = {5,15,30};
const int GOALKEEPER_VALUES [3] = {10,10,15};
const int BALL_VALUES [3] = {15,20,30};
const int REFEREE_TIME_VALUES [3] = {2,2,4};

#pragma mark Initialization:

Gem::Gem(string name){
    spriteName = name;
    opponent = false;
}

void Gem::load(Output*output){
    outputFacade = output;
    fieldWidth = Constants::FIELD_WIDTH-2*Constants::FIELD_LINE_WIDTH;

    width = 1+fieldWidth/Constants::GEMS_PER_ROW;
    selected = false;
    willBeDeleted = false;
    moving = false;
    goingToFirstStop = false;
    fieldX = (Constants::GAME_SCREEN_WIDTH-Constants::FIELD_WIDTH)/2;
    fieldY = (Constants::GAME_SCREEN_HEIGHT-Constants::FIELD_WIDTH)/2;
}

void Gem::setOpponent(){
    opponent = true;
}
#pragma mark Direction and Position:

void Gem::setPos(int gridX, int gridY){
    x = Constants::FIELD_LINE_WIDTH+ fieldX+gridX*(width);
    y = Constants::FIELD_LINE_WIDTH+ fieldY+gridY*(width);
    boardX = gridX;
    boardY = gridY;
}

void Gem::setNewDirection(int gridX, int gridY){
    moving = true;
    finalX = Constants::FIELD_LINE_WIDTH+ fieldX+gridX*(width);
    finalY = Constants::FIELD_LINE_WIDTH+ fieldY+gridY*(width);
    float xDist = Constants::FIELD_LINE_WIDTH+fieldX+boardX*(width) - x;
    float yDist = Constants::FIELD_LINE_WIDTH+fieldY+boardY*(width) - y;
    float distance = sqrtf(xDist*xDist + yDist*yDist);
    xVector = Constants::GEM_VELOCITY * xDist / distance;
    yVector = Constants::GEM_VELOCITY  * yDist / distance;
}

void Gem::setInitialAnimationPosition(){//hacer valores relativos
    moving = true;
    finalY = fieldY+Constants::FIELD_LINE_WIDTH+(fieldWidth-width)/2;
    y = finalY;
    if(boardX<4){
        //finalX = 159;
        finalX = fieldX-2*width;
        x = width - boardY*(width) - boardX*(4*width);
    }
    else{
        //finalX = 860;
        finalX = fieldX+Constants::FIELD_WIDTH+width;
        x = Constants::GAME_SCREEN_WIDTH-2*width + boardY*(width) + abs((boardX-7))*(4*width);
    }
    float xDist = fieldX+boardX*(width) - x;
    float yDist = 0;
    float distance = sqrtf(xDist*xDist + yDist*yDist);
    xVector = Constants::GEM_VELOCITY * xDist / distance;
    yVector = Constants::GEM_VELOCITY * yDist / distance;
    goingToFirstStop = true;
    
}

void Gem::setNextPos(int gridY){
    boardY = gridY;
    setNewDirection(boardX, boardY);
}

#pragma mark Game Cycle:

void Gem::render(){
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
        if(fabsf(finalX-x) < Constants::GEM_VELOCITY && fabsf(finalY-y)<Constants::GEM_VELOCITY){
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
        width-=3;
        x+=1.5;
        y+=1.5;
        if(width<5){
            willBeDeleted = false;
        }
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

void Gem::setMoving(bool move){
    moving = move;
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

bool Gem::isOpponent(){
    return opponent;
}

int Gem::getValue(int sequenceNumber){
    int position = sequenceNumber-3;
    if(getType() == "Referee"){
        return REFEREE_TIME_VALUES[position];
    }
    else if (getType() == "Goalkeeper"){
        return GOALKEEPER_VALUES[position];
    }
    else if(getType() == "Ball"){
        return BALL_VALUES[position];
    }
    else if(opponent){
        return OPPONENT_VALUES[position];
    }
    return PLAYER_VALUES[position];
}

#pragma mark Destructor:

Gem::~Gem(){
    
}
