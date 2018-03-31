//
//  FieldSwitchingGems.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/31/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Field.hpp"
#include "EventType.hpp"
#include "FieldSwitchingGems.hpp"
bool switchingBack = false;

FieldState* FieldSwitchingGems::handleInput(EventType e, Field &f){
    return NULL;
}


FieldState* FieldSwitchingGems::update(Field &f){
        firstGem->setSelected(false);
        secondGem->setSelected(false);
        firstGem->update();
        secondGem->update();
        if(!firstGem->isMoving() && !secondGem->isMoving()){
            if(switchingBack){
                switchingBack = false;
                return new FieldWaiting();
            }
            if(f.makeSwitch()){
                f.destroyGems();
                FieldDestroyingGems* state = new FieldDestroyingGems();
                state->setGemsToDestroy(f.gemsToDestroy);
                return state;
            }
            else{
                int firstX = firstGem->boardX;
                int firstY = firstGem->boardY;
                f.switchGems(firstGem, secondGem);
                firstGem->switchWithGem(secondGem->boardX, secondGem->boardY);
                secondGem->switchWithGem(firstX, firstY);
                switchingBack = true;
            }
    }
    return NULL;
}

void FieldSwitchingGems::render(Field &f){
    
}

void FieldSwitchingGems::setGems(Gem* gem1, Gem* gem2){
    firstGem = gem1;
    secondGem = gem2;
}


