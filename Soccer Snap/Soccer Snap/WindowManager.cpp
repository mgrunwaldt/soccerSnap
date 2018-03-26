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
    loaderScene = new Loader(output, input);
    mainMenuScene = new MainMenu(output,input);
    gameScene = new GameScene(output,input);
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
    loaderScene->load();
    activeScene = loaderScene;
    presentScene();
    mainMenuScene->load();
    this->showMainMenu();
    delete loaderScene;
}

void WindowManager::showMainMenu(){
    activeScene = mainMenuScene;
    presentScene();
    int chosenCountry = mainMenuScene->getChosenCountry();
    showGameScreen(chosenCountry);
    delete mainMenuScene;
}

void WindowManager::showGameScreen(int country){
    gameScene->setDuration(130);
    gameScene->load();
    activeScene = gameScene;
    presentScene();
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
