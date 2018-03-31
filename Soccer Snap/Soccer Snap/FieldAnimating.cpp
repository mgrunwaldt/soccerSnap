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
    bool finishedAnimating = f.moveGems();
    if(finishedAnimating){
        f.setReadyToStart();
        return new FieldWaiting();
    }
    return NULL;
}

void FieldAnimating::render(Field &f){
    
}
