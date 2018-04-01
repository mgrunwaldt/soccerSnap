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
            keepsDestroying = true;
        }
    }
    if(!keepsDestroying){
        addPoints(f);
        return new FieldGemsGoingDown();
    }
    return NULL;
}

void FieldDestroyingGems::setGemsToDestroy(vector<Gem*> gems){
    gemsToDestroy = gems;
}

void FieldDestroyingGems::render(Field &f){
    for(int i = 0;i < gemsToDestroy.size(); i++){
        if(gemsToDestroy[i]->needsDelete()){
            gemsToDestroy[i]->render();
        }
    }
}

void FieldDestroyingGems::addPoints(Field &f){
    for(int i = 0;i<f.gemsBy3.size();i++){
        Gem* gem = f.gemsBy3[i];
        int value = gem->getValue(3);
        if(gem->getType() == "Referee"){
            f.addTime(value);
        }
        else if (gem->getType() == "Goalkeeper"){
            f.addOpponentPoints(-value);
        }
        else if(gem->isOpponent()){
            f.addOpponentPoints(value);
        }
        else{
            f.addPoints(value);
        }
    }
    for(int i = 0;i<f.gemsBy4.size();i++){
        Gem* gem = f.gemsBy4[i];
        int value = gem->getValue(4);
        if(gem->getType() == "Referee"){
            f.addTime(value);
        }
        else if (gem->getType() == "Goalkeeper"){
            f.addOpponentPoints(-value);
        }
        else if(gem->isOpponent()){
            f.addOpponentPoints(value);
        }
        else{
            f.addPoints(value);
        }
    }
    for(int i = 0;i<f.gemsBy5.size();i++){
        Gem* gem = f.gemsBy5[i];
        int value = gem->getValue(5);
        if(gem->getType() == "Referee"){
            f.addTime(value);
        }
        else if (gem->getType() == "Goalkeeper"){
            f.addOpponentPoints(-value);
        }
        else if(gem->isOpponent()){
            f.addOpponentPoints(value);
        }
        else{
            f.addPoints(value);
        }
    }
    for(int i = 0;i<f.gemsByT.size();i++){
        Gem* gem = f.gemsByT[i];
        int value = gem->getValue(5);
        if(gem->getType() == "Referee"){
            f.addTime(value);
        }
        else if (gem->getType() == "Goalkeeper"){
            f.addOpponentPoints(-value);
        }
        else if(gem->isOpponent()){
            f.addOpponentPoints(value);
        }
        else{
            f.addPoints(value);
        }
    }
}
