//
//  WindowManager.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/25/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "WindowManager.hpp"


Uint32 frameStart;
float frameTime;


WindowManager::WindowManager(){
    output = new Output();
    input = new Input();
    output->init();
}

WindowManager::~WindowManager(){
    
}

void WindowManager::presentScene(){
 //   std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    while (activeScene->isActive()) {
        frameStart = Tools::getTicks();
        
        activeScene->handleEvents();
        activeScene->update();
        activeScene->render();
        
        frameTime = Tools::getTicks()- frameStart;
        if(Constants::frameDelay>frameTime){
            Tools::delay(Constants::frameDelay-frameTime);
        }
    }

}

void WindowManager::showLoader(){
    loaderScene = new Loader(output, input);
    loaderScene->load();
    activeScene = loaderScene;
    presentScene();
    delete loaderScene;
    this->showMainMenu();
    
}

void WindowManager::showMainMenu(){
    mainMenuScene = new MainMenu(output,input);
    mainMenuScene->load();
    activeScene = mainMenuScene;
    presentScene();
    int chosenCountry = mainMenuScene->getChosenCountry();
    delete mainMenuScene;
    showGameScreen(chosenCountry);
    
}

void WindowManager::showGameScreen(int country){
    gameScene = new GameScene(output,input);
    gameScene->setCountries(country);
    gameScene->setDuration(130);
    gameScene->load();
    activeScene = gameScene;
    presentScene();
    delete gameScene;
    showMainMenu();
    /*game = new Game();
     game->init();
     game->run();*/
}

/*
void WindowManager::render(){
    output->clearScreen();
    //dibujo todo
    field->drawField();
    
    
    
    output->drawScreen();
    
}
*/

/*
    while activeScene->isRunning
        activeScene->handleEvents
        activeScene->update
        activeScene->render
 */
