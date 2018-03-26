//
//  GameScene.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/26/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "GameScene.hpp"
#pragma mark Setup:

GameScene::GameScene(Output* o, Input* i){
    output = o;
    input = i;
    active = true;
    points = 0;
    opponentPoints = 1500;//Cambiar
}

GameScene::~GameScene(){
    
}

void GameScene::load(){
    loadTimer();
    loadGUIElements();
    loadField();
    
}

void GameScene::setMyCountry(int countryPos){
    selectedCountry = countryPos;
}

void GameScene::setDuration(int time){
    duration = time;
}
void GameScene::loadTimer(){
    gameTimer = new Timer(output,duration);
    gameTimer->start();
}

#pragma mark Cycle:

void GameScene::handleEvents(){
    while (input->eventsLeft()) {
        EventType e = input->checkEvent();
        homeButton->handleEvent(e);
        pauseButton->handleEvent(e);
    }
    
}
void GameScene::update(){
    if(gameTimer->isActive()){
        gameTimer->update();
    }
}

void GameScene::render(){
    output->clearScreen();
    
    renderImages();
    renderPoints();
    gameTimer->render();
    homeButton->render();
    pauseButton->render();
    output->drawScreen();
}

void GameScene::clean(){
    
}

#pragma mark Actions:
void GameScene::addPoints(int pointsToAdd){
    points+=pointsToAdd;
}

void GameScene::addOpponentPoints(int pointsToAdd){
    opponentPoints += pointsToAdd;
}

bool GameScene::isActive(){
    return active;
}



#pragma mark: GUI Load

void GameScene::renderPoints(){
    int thousandPlayerPointUnit = points/1000 % 10;
    int hundredPlayerPointUnit = points/100 % 10;
    int tenPlayerPointUnit = points/10 % 10;
    int playerPointUnit = points% 10;
    
    int thousandOpponentPointUnit = opponentPoints/1000 % 10;
    int hundredOpponentPointUnit = opponentPoints/100 % 10;
    int tenOpponentPointUnit = opponentPoints/10 % 10;
    int opponentPointUnit = opponentPoints% 10;
    
    std::string name = "Score";

    char* thousandPlayerPointSpriteName = strdup((name+std::to_string(thousandPlayerPointUnit)).c_str());
    char* hundredPlayerPointSpriteName = strdup((name+std::to_string(hundredPlayerPointUnit)).c_str());
    char* tenPlayerPointSpriteName = strdup((name+std::to_string(tenPlayerPointUnit)).c_str());
    char* playerPointSpriteName = strdup((name+std::to_string(playerPointUnit)).c_str());

    char* thousandOpponentPointSpriteName = strdup((name+std::to_string(thousandOpponentPointUnit)).c_str());
    char* hundredOpponentPointSpriteName = strdup((name+std::to_string(hundredOpponentPointUnit)).c_str());
    char* tenOpponentPointSpriteName = strdup((name+std::to_string(tenOpponentPointUnit)).c_str());
    char* opponentPointSpriteName = strdup((name+std::to_string(opponentPointUnit)).c_str());
    
    output->addSprite(thousandPlayerPointSpriteName, 355, 649, 34);
    output->addSprite(hundredPlayerPointSpriteName, 389, 649, 34);
    output->addSprite(tenPlayerPointSpriteName, 423, 649, 34);
    output->addSprite(playerPointSpriteName, 457, 649, 34);
    
    output->addSprite(thousandOpponentPointSpriteName, 581, 649, 34);
    output->addSprite(hundredOpponentPointSpriteName, 615, 649, 34);
    output->addSprite(tenOpponentPointSpriteName, 649, 649, 34);
    output->addSprite(opponentPointSpriteName, 683, 649, 34);

}


void GameScene::renderImages(){
    output->addSprite("Field", 262, 92, 545);
    output->addSprite("Board", 457, 18, 154);
    output->addSprite("Board", 351, 645, 144,63);
    output->addSprite("Board", 577, 645, 144,63);
    output->addSprite("VsLabel", 521, 686, 34);
    output->addSprite("LogoBall", 988, 12, 38);
    output->addSprite("Logo", 847, 20, 161);
}

void GameScene::loadGUIElements(){
    char* pauseButtonSprites[3]={"PauseButtonOut","PauseButtonOver","PauseButtonIn"};
    pauseButton = new Button(output,input,pauseButtonSprites);
    pauseButton->setPosition(100, 20);
    
    char* menuButtonSprites[3]={"MenuButtonOut","MenuButtonOver","MenuButtonIn"};
    homeButton = new Button(output,input,menuButtonSprites);
    homeButton->setPosition(30, 20);
   
    
}

void GameScene::loadField(){
        
}
