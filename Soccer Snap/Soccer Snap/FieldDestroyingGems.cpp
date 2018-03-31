//
//  FieldDestroyingGems.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/31/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Field.hpp"
#include "EventType.hpp"
#include "FieldDestroyingGems.hpp"

FieldState* FieldDestroyingGems::handleInput(EventType e, Field &f){
    return NULL;
}

FieldState* FieldDestroyingGems::update(Field &f){
    bool keepsDestroying = false;
    for(int i = 0;i < gemsToDestroy.size(); i++){
        gemsToDestroy[i]->update();
        if(gemsToDestroy[i]->needsDelete()){
            //keepsDestroying = true; si le quiero poner animacion es aca
        }
        if(!keepsDestroying){
           /* ;*/
            return new FieldGemsGoingDown();
        }

    }
    return NULL;
}

void FieldDestroyingGems::setGemsToDestroy(vector<Gem*> gems){
    gemsToDestroy = gems;
}

void FieldDestroyingGems::render(Field &f){
 /*   bool keepsDestroying = false;
    for(int i = 0;i < gemsToDestroy.size(); i++){
        gemsToDestroy[i]->render();
        if(gemsToDestroy[i]->needsDelete()){
            //keepsDestroying = true; si le quiero poner animacion es aca
        }
    }*/
}
