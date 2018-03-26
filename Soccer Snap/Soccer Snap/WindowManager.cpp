//
//  WindowManager.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/25/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "WindowManager.hpp"
#include <chrono>
#include <thread>

const float FPS = 60;
const float frameDelay = 1000/FPS;
Uint32 frameStart;
float frameTime;


WindowManager::WindowManager(){
    output = new Output();
    input = new Input();
    output->init();
    loaderScene = new Loader(output, input,FPS);
    mainMenuScene = new MainMenu(output,input);
}

WindowManager::~WindowManager(){
    
}

void WindowManager::presentScene(){
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    while (activeScene->isActive()) {
        frameStart = Tools::getTicks();
        
        activeScene->handleEvents();
        activeScene->update();
        activeScene->render();
        
        frameTime = Tools::getTicks()- frameStart;
        if(frameDelay>frameTime){
            Tools::delay(frameDelay-frameTime);
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
}

void WindowManager::showGameScreen(){
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
