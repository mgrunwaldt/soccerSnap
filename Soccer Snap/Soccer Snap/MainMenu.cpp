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
        if(playButton->isSelected()){
            exit(0);
        }
        for(int i = 0;i<5;i++){
            bool selectedBefore = countryButtons[i]->isSelected();
            countryButtons[i]->handleEvent(e);
            bool selectedAfter = countryButtons[i]->isSelected();
            if(!selectedBefore && selectedAfter){
                for(int j = 0;j<5;j++){
                    if(i != j)
                        countryButtons[j]->setSelected(false);
                }
            }
            selectedCountry = i;
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
        int labelXPos = 64+i*193;
        int labelYPos = 453;
        std::string labelExtension = "Label";
        std::string labelName = countries[i]+labelExtension;
        char* labelSpriteName = strdup(labelName.c_str());
        output->addSprite(labelSpriteName, labelXPos, labelYPos, 175);
        
        int shirtXPos = 88+i*193;
        int shirtYPos = 283;
        std::string shirtExtension = "Menu";
        std::string shirtName = countries[i]+shirtExtension;
        char* shirtSpriteName = strdup(shirtName.c_str());
        output->addSprite(shirtSpriteName, shirtXPos, shirtYPos, 132);
        

    }
    output->addSprite("LogoBall", 666, 13, 93);
    output->addSprite("Logo", 321, 35, 391);
    output->addSprite("PickTeam", 450, 184, 162);
    output->addSprite("MenuSeparator", 64, 215, 946);
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
    countryButtons[0]->setSelected(true);
    selectedCountry = 0;

}
