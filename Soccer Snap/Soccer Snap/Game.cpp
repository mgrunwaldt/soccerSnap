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
    prueba = new Gem();
    prueba->load(output,"Italy", 70);

    prueba2 = new Gem();
    prueba2->load(output,"Italy", 70);
    
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
    prueba->update();
}

void Game::render(){
    output->clearScreen();
    //dibujo todo
    
    prueba->draw();
    prueba2->draw();

    
    output->drawScreen();

}

void Game::clean(){
    delete input;
    delete output;
}


