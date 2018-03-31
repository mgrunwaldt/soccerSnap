//
//  GamePlaying.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/30/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "GameScene.hpp"
#include "EventType.hpp"
#include "GamePlaying.hpp"

GameState* GamePlaying::handleInput(EventType e, GameScene &g){
    g.pauseButton->handleEvent(e);
    if(g.pauseButton->isSelected()){
        g.pauseButton->setSelected(false);
        return new GamePaused();
    }
    g.handleFieldEvent(e);
    return NULL;
}


GameState* GamePlaying::update(GameScene &g){
    g.updateTimer();
    g.updateField();
    if(g.hasFinished()){
        return new GameFinished();
    }
    return NULL;
}

void GamePlaying::render(GameScene &g){
    g.showPauseButton();
}

