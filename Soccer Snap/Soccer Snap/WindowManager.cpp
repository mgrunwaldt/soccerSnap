//
//  WindowManager.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/25/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "WindowManager.hpp"

#pragma mark Inicialization:

WindowManager::WindowManager(){
    try{
        output = new Output();
        input = new Input();
        output->init();
        gameRunning = true;
        
    }
    catch (OutputInitException ex){
        cout << ex.what() << endl;
        cout << ex.getMessage() << endl;
    }
    
}

#pragma mark Scene Presentation:

void WindowManager::showLoader(){
    loaderScene = new Loader(output, input);
    loaderScene->load();
    activeScene = loaderScene;
    presentScene();
    delete loaderScene;
    if(gameRunning){
        this->showMainMenu();
    }
}

void WindowManager::showMainMenu(){
    mainMenuScene = new MainMenu(output,input);
    mainMenuScene->load();
    activeScene = mainMenuScene;
    presentScene();
    if(mainMenuScene->toGame()){
        int chosenCountry = mainMenuScene->getChosenCountry();
        delete mainMenuScene;
        if(gameRunning){
            showGameScreen(chosenCountry);
        }
    }
    else{
        delete mainMenuScene;
        if(gameRunning){
            showRulesScreen();
        }
    }
}

void WindowManager::showRulesScreen(){
    rulesScene = new Rules(output, input);
    rulesScene->load();
    activeScene = rulesScene;
    presentScene();
    delete rulesScene;
    if(gameRunning){
        this->showMainMenu();
    }
}

void WindowManager::showGameScreen(int country){
    gameScene = new GameScene(output,input);
    gameScene->setCountries(country);
    gameScene->load();
    activeScene = gameScene;
    presentScene();
    delete gameScene;
    if(gameRunning){
        showMainMenu();
    }
}

void WindowManager::presentScene(){
    while (activeScene->isActive() && gameRunning) {
        frameStart = Tools::getTicks();
        while (input->eventsLeft()) {
            EventType e = input->checkEvent();
            if(e != EventType::Unknown){
                if(e == EventType::Exit){
                    gameRunning = false;
                }
                activeScene->handleEvent(e);
            }
            
        }
        
        activeScene->update();
        output->clearScreen();
        activeScene->render();
        output->drawScreen();
        frameTime = Tools::getTicks()- frameStart;
        if(Constants::FRAME_DELAY>frameTime){
            Tools::delay(Constants::FRAME_DELAY-frameTime);
        }
    }
    
    if(!gameRunning){
        delete this;
    }

}



#pragma mark Delete:

WindowManager::~WindowManager(){
    delete output;
    delete input;
}
