//
//  FieldAnimating.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/30/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Field.hpp"
#include "EventType.hpp"
#include "FieldAnimating.hpp"

FieldState* FieldAnimating::handleInput(EventType e, Field &f){
    return NULL;
}


FieldState* FieldAnimating::update(Field &f){
    bool allOk = true;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            Gem* toDraw = f.gems[i][j];
            toDraw->update();
            if(toDraw->isMoving())
                allOk = false;
        }
    }
    if(allOk){
        state = FieldStates::WAITING;
        gameNeedsToStart = true;
    }

    return NULL;
}

/*
 
 */
