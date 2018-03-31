//
//  FieldGemsGoingDown.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/31/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Field.hpp"
#include "EventType.hpp"
#include "FieldGemsGoingDown.hpp"

FieldState* FieldGemsGoingDown::handleInput(EventType e, Field &f){
    return NULL;
}


FieldState* FieldGemsGoingDown::update(Field &f){
    bool isGoingDown = false;
    for(int i=0;i<Constants::GEMS_PER_ROW;i++){
        for(int j=0;j<Constants::GEMS_PER_ROW;j++){
            Gem* toDraw = f.getGem(i, j);
            toDraw->update();
            if(toDraw->isMoving()){
                isGoingDown = true;
            }
        }
    }
    if(!isGoingDown){
        if(f.makeSwitch()){
            f.destroyGems();
            FieldDestroyingGems* state = new FieldDestroyingGems();
            state->setGemsToDestroy(f.gemsToDestroy);
            return state;
        }
        else{
            return new FieldWaiting();
        }
    }
    return NULL;
}


void FieldGemsGoingDown::render(Field &f){
    
}

