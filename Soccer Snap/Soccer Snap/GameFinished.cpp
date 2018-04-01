//
//  GameFinished.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/30/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "GameScene.hpp"
#include "EventType.hpp"
#include "GameFinished.hpp"

GameState* GameFinished::handleInput(EventType e, GameScene &g){
    if(boardUp){
        homeButton->handleEvent(e);
        if(homeButton->isSelected()){
            g.hideEndAnimation();
        }
        playAgainButton->handleEvent(e);
        if(playAgainButton->isSelected()){
            g.load();
            return new GameLoading();
        }
    }
    
    return NULL;
}


GameState* GameFinished::update(GameScene &g){
    
    if(!buttonsInitialized){
        string homeButtonSprites[3]={"EndHomeOut","EndHomeOver","EndHomeDown"};
        homeButton = new Button(g.output,g.input,homeButtonSprites);
        string playAgainSprites[3]={"EndPlayAgainOut","EndPlayAgainOver","EndPlayAgainDown"};
        playAgainButton = new Button(g.output,g.input,playAgainSprites);
        buttonsInitialized = true;
    }
    boardSize = g.output->getSpriteDimensions("EndBoard");
    if(!boardUp){
        boardY-=8;

        if(boardY <= Constants::GAME_SCREEN_HEIGHT-boardSize.y +8 ){
            boardUp = true;
        }
    }
    
    

    return NULL;
}

void GameFinished::render(GameScene &g){
    Point winCupSize = g.output->getSpriteDimensions("EndWinCup");
    Point buttonSize = g.output->getSpriteDimensions("EndHomeOut");

    g.output->addSprite("EndBoard", (Constants::GAME_SCREEN_WIDTH-boardSize.x)/2, boardY, boardSize.x);
    if(buttonsInitialized){
        homeButton->setPosition((Constants::GAME_SCREEN_WIDTH-winCupSize.x)/2 - 25 - buttonSize.x, boardY + 90 +winCupSize.y - buttonSize.y );
        playAgainButton->setPosition((Constants::GAME_SCREEN_WIDTH-winCupSize.x)/2 + 25 + winCupSize.x , boardY + 90 +winCupSize.y - buttonSize.y);
        homeButton->render();
        playAgainButton->render();
    }
    

    
    if(g.hasWon()){
        Point winTextSize = g.output->getSpriteDimensions("EndWinText");

        g.output->addSprite("EndWinText", (Constants::GAME_SCREEN_WIDTH-winTextSize.x)/2, boardY + 60, winTextSize.x);
        g.output->addSprite("EndWinCup", (Constants::GAME_SCREEN_WIDTH-winCupSize.x)/2, boardY + 70 + winTextSize.y , winCupSize.x);
    }
    else{
        Point loseTextSize = g.output->getSpriteDimensions("EndLoseText");
        Point loseMedalSize = g.output->getSpriteDimensions("EndLoseMedal");

        g.output->addSprite("EndLoseText", (Constants::GAME_SCREEN_WIDTH-loseTextSize.x)/2, boardY + 60, loseTextSize.x);
        g.output->addSprite("EndLoseMedal", (Constants::GAME_SCREEN_WIDTH-loseMedalSize.x)/2, boardY + 70 + loseTextSize.y , loseMedalSize.x);
    }
}
