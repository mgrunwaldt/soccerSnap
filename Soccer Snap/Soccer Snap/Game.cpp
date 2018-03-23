//
//  Game.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/21/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Game.hpp"


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

void Game::handleEvents(){
    switch (input->checkEvent()) {
        case EventType::Exit:
            isRunning = false;
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


