//
//  GameScene.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/26/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "GameScene.hpp"

#pragma mark Inicialization:

GameScene::GameScene(Output* o, Input* i){
    output = o;
    input = i;
    active = true;
    points = 0;
    opponentPoints = Constants::TARGET_POINTS;
    duration = Constants::MATCH_TIME;
    srand(time(NULL));
}

void GameScene::load(){
    state = new GameLoading();
    loadTimer();
    loadGUIElements();
    loadField();
}


void GameScene::loadTimer(){
    gameTimer = new Timer(output,duration);
}

void GameScene::loadGUIElements(){
    string pauseButtonSprites[3]={"PauseButtonOut","PauseButtonOver","PauseButtonIn"};
    pauseButton = new Button(output,input,pauseButtonSprites);
    pauseButton->setPosition(342, 23);
    
    string menuButtonSprites[3]={"MenuButtonOut","MenuButtonOver","MenuButtonIn"};
    homeButton = new Button(output,input,menuButtonSprites);
    homeButton->setPosition(272, 23);
    
    
}

void GameScene::loadField(){
    field = new Field(output, input);
    field->load(selectedCountry,opponentCountry);
}

void GameScene::setCountries(int countryPos){
    selectedCountry = countries[countryPos];
    bool foundCorrect = false;
    while(!foundCorrect){
        int randNum = rand()%(5);
        if(randNum != countryPos){
            opponentCountry = countries[randNum];
            foundCorrect = true;
        }
    }
}

#pragma mark Cycle:

void GameScene::handleEvent(EventType e){
    GameState* newState = state->handleInput(e,*this);
    if(newState != NULL){
        delete state;
        state = newState;
    }
    /*
    homeButton->handleEvent(e);
    if(homeButton->isSelected()){
        goToMainMenu();
    }
    pauseButton->handleEvent(e);
    if(pauseButton->isSelected()){
        //parar timer, poner play
    }
    field->handleEvent(e);*/
}
    
void GameScene::update(){
    GameState* newState = state->update(*this);
    if(newState != NULL){
        delete state;
        state = newState;
    }
    
    /*field->update();
    if(field->needsToStart()){
        gameTimer->start();
        field->start();
    }
    if(gameTimer->isActive()){
        gameTimer->update();
    }*/
}

void GameScene::updateField(){
    field->update();
}

bool GameScene::fieldLoaded(){
    return field->needsToStart();
}

void GameScene::render(){
    renderImages();
    renderPoints();
    gameTimer->render();
    homeButton->render();
    pauseButton->render();
    
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

void GameScene::goToMainMenu(){
    active = false;
}



#pragma mark Render:

void GameScene::renderPoints(){
    int thousandPlayerPointUnit = points/1000 % 10;
    int hundredPlayerPointUnit = points/100 % 10;
    int tenPlayerPointUnit = points/10 % 10;
    int playerPointUnit = points% 10;
    
    int thousandOpponentPointUnit = opponentPoints/1000 % 10;
    int hundredOpponentPointUnit = opponentPoints/100 % 10;
    int tenOpponentPointUnit = opponentPoints/10 % 10;
    int opponentPointUnit = opponentPoints% 10;
    
    string name = "Score";

    string thousandPlayerPointSpriteName = name+to_string(thousandPlayerPointUnit);
    string hundredPlayerPointSpriteName = name+to_string(hundredPlayerPointUnit);
    string tenPlayerPointSpriteName = name+to_string(tenPlayerPointUnit);
    string playerPointSpriteName = name+to_string(playerPointUnit);
    
    string thousandOpponentPointSpriteName = name+to_string(thousandOpponentPointUnit);
    string hundredOpponentPointSpriteName = name+to_string(hundredOpponentPointUnit);
    string tenOpponentPointSpriteName = name+to_string(tenOpponentPointUnit);
    string opponentPointSpriteName = name+to_string(opponentPointUnit);
    
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
    output->addSprite("Field", (Constants::GAME_SCREEN_WIDTH-Constants::FIELD_WIDTH)/2, (Constants::GAME_SCREEN_HEIGHT-Constants::FIELD_WIDTH)/2, Constants::FIELD_WIDTH);
    output->addSprite("Board", 351, 645, 144,63);
    output->addSprite("Board", 577, 645, 144,63);
    output->addSprite("VsLabel", 521, 686, 34);
    output->addSprite("Goalkeeper", 726, 18, 64);

    output->addSprite("StadiumFloor", -55, 0, 265,720);
    output->addSprite("StadiumFloor", 862, 0,265, 720,180);
    field->render();
    output->addSprite("UruguayFans", -55, 0, 265,720);
    output->addSprite("UruguayFans", 862, 0,265, 720,180);
    
    string name = "Menu";
    string countryString = selectedCountry+name;
    string opponentString = opponentCountry+name;
    
    output->addSprite(countryString, 283, 645, 51);
    output->addSprite(opponentString, 736, 645, 51);
    
}



#pragma mark Destructor:
GameScene::~GameScene(){
    delete homeButton;
    delete pauseButton;
    delete gameTimer;
    delete field;
}
