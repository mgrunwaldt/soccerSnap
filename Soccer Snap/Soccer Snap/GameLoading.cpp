//
//  GameLoading.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/30/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//
#include "GameScene.hpp"
#include "EventType.hpp"
#include "GameLoading.hpp"

GameState* GameLoading::handleInput(EventType e, GameScene &g){
    /*if(e == EventType::MouseDown || e == EventType::MouseUp){
        g.skipLoader();
        return new GamePlaying();
    }*/
    return NULL;
}

GameState* GameLoading::update(GameScene &g){
    g.updateField();
    if(g.fieldLoaded()){
        return new GamePlaying();
    }
    return NULL;
}

void GameLoading::render(GameScene &g){

}
