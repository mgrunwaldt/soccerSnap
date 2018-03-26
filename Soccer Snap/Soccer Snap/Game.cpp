//
//  Game.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/21/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Game.hpp"

/*const int FPS = 60;
const int frameDelay = 1000/FPS;
Uint32 frameStart;
int frameTime;

Game::Game(){

}

Game::~Game(){

}

void Game::init(){
    output = new Output();
    input = new Input();
    
    field = new Field(output);
    field->loadField();
    
    if(output->init()){
        isRunning = true;
    }
    else {
        isRunning = false;
    }
}

void Game::run(){
    
    

    while (isRunning) {
        frameStart = Tools::getTicks();
        
        handleEvents();
        update();
        render();
        
        frameTime = Tools::getTicks()- frameStart;
        
        if(frameDelay>frameTime){
            Tools::delay(frameDelay-frameTime);
        }
    }
    
    clean();

}

ScreenComponent Game::getClickedArea(Point p){
    int res = output->getRes();
    if(p.x>field->FIELD_X && p.x < field->FIELD_X + field->FIELD_WIDTH && p.y>field->FIELD_Y && p.y < field->FIELD_Y + field->FIELD_WIDTH){
        return Canvas;
    }
    return Other;
}

void Game::homeUp(){

}
void Game::homeDown(){
    
}

void Game::pauseUp(){
    
}

void Game::pauseDown(){

}


void Game::handleEvents(){
    Point p;
    switch (input->checkEvent()) {
        case EventType::Exit:
            isRunning = false;
        break;
        case EventType::MouseDown:
            p=input->getMousePosition();
            switch (getClickedArea(p)) {
                case Canvas:
                    field->mouseDown(p);
                    break;
                case Pause:
                    pauseDown();
                    break;
                case Home:
                    homeDown();
                    break;
                default:
                    break;
            }
            break;
        case EventType::MouseUp:
            p=input->getMousePosition();
            switch (getClickedArea(p)) {
                case Canvas:
                    field->mouseUp(p);
                    break;
                case Pause:
                    pauseUp();
                    break;
                case Home:
                    homeUp();
                    break;
                default:
                    break;
            }
            break;

            break;
            
        default:
            break;
    }
}

void Game::update(){

}

void Game::render(){
    output->clearScreen();
    //dibujo todo
    field->drawField();


    
    output->drawScreen();

}

void Game::clean(){
    delete input;
    delete output;
}
*/

