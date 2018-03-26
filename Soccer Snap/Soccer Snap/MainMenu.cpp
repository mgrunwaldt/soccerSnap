//
//  MainMenu.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/25/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "MainMenu.hpp"

MainMenu::MainMenu(Output* o, Input* i){
    output = o;
    input = i;
    active = true;
}

MainMenu::~MainMenu(){
    
}

void MainMenu::load(){
    loadPlayButton();
    loadCountries();
    
}

void MainMenu::handleEvents(){
    while (input->eventsLeft()) {
        EventType e = input->checkEvent();
        playButton->handleEvent(e);
        for(int i = 0;i<5;i++){
            countryButtons[i]->handleEvent(e);
        }
    }
   
}
void MainMenu::update(){

}

void MainMenu::render(){
    output->clearScreen();
    playButton->render();
    for(int i = 0;i<5;i++){
        countryButtons[i]->render();
    }
    output->drawScreen();
}

void MainMenu::clean(){
    
}


bool MainMenu::isActive(){
    return active;
}

#pragma mark: GUI Setup

void MainMenu::loadPlayButton(){
    char* buttonSprites[3]={"PlayOut","PlayOver","PlayDown"};
    playButton = new Button(output,input,buttonSprites);
    playButton->setPosition(410, 560);
}

void MainMenu::loadCountries(){
    char* backSprites[3]={"CountryBack","CountryBack","CountryBack"};
    int alphas [3]= {0,115,76};
    for(int i = 0;i<5;i++){
        Button* countryButton = new Button(output,input,backSprites);
        countryButton->setAlphas(alphas);
        int xPos = 64+i*193;
        int yPos = 249;
        countryButton->setPosition(xPos, yPos);
        countryButtons[i] = countryButton;
    }

}
