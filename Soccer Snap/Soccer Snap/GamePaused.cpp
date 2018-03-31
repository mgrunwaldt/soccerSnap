//
//  GamePaused.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/30/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "GameScene.hpp"
#include "EventType.hpp"
#include "GamePaused.hpp"

GameState* GamePaused::handleInput(EventType e, GameScene &g){
    g.playButton->handleEvent(e);
    if(g.playButton->isSelected()){
        g.playButton->setSelected(false);

        return new GamePlaying();
    }
    return NULL;
}


GameState* GamePaused::update(GameScene &g){
    return NULL;
}

void GamePaused::render(GameScene &g){
    g.showPlayButton();
}
