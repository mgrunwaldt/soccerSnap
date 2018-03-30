//
//  MainMenu.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/25/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "MainMenu.hpp"

const float backMargin = 64;
int countrySeparation;

#pragma mark Setup:

MainMenu::MainMenu(Output* o, Input* i){
    output = o;
    input = i;
    active = true;
}

void MainMenu::load(){
    loadPlayButton();
    loadCountries();
    loadPositions();
}

#pragma mark GUI Load:

void MainMenu::loadPlayButton(){
    string buttonSprites[3]={"PlayOut","PlayOver","PlayDown"};
    playButton = new Button(output,input,buttonSprites);
    Point playButtonSize = output->getSpriteDimensions("PlayOut");
    int playX = (Constants::GAME_SCREEN_WIDTH-playButtonSize.x)/2;
    playButton->setPosition(playX, Constants::GAME_SCREEN_HEIGHT*0.83);
}

void MainMenu::loadCountries(){
    Point backSize = output->getSpriteDimensions("CountryBack");
    int screenWithoutMargins = Constants::GAME_SCREEN_WIDTH - (2*backMargin);
    int buttonSeparation = (screenWithoutMargins-5*backSize.x)/4;
    countrySeparation = buttonSeparation+backSize.x;
    string backSprites[3]={"CountryBack","CountryBack","CountryBack"};
    int alphas [3]= {0,115,76};
    for(int i = 0;i<5;i++){
        Button* countryButton = new Button(output,input,backSprites);
        countryButton->setAlphas(alphas);
        
        int xPos = backMargin + i*countrySeparation;
        
        int yPos = Constants::GAME_SCREEN_HEIGHT *0.37;
        countryButton->setPosition(xPos, yPos);
        countryButtons[i] = countryButton;
    }
    countryButtons[0]->setSelected(true);
    selectedCountry = 0;
    
}

void MainMenu::loadPositions(){
    pickTeamDimensions = output->getSpriteDimensions("PickTeam");
    separatorDimensions = output->getSpriteDimensions("MenuSeparator");
    ballDimensions = output->getSpriteDimensions("LogoBall");
    logoDimensions = output->getSpriteDimensions("Logo");
    float combinedWidth = logoDimensions.x*(9.0/8.0) / 2;
    float combinedHeight = logoDimensions.y*(48.0/41.0) / 2;
    
    logoX = Constants::GAME_SCREEN_WIDTH/2 - (combinedWidth/2);
    ballX = logoX + Constants::LOGO_BALL_X_PROPORTION * logoDimensions.x/2;
    
    ballY = Constants::GAME_SCREEN_HEIGHT*0.04;
    logoY = ballY + Constants::BALL_LOGO_Y_PROPORTION * ballDimensions.y/2;
}


#pragma mark Game Cycle:

void MainMenu::handleEvent(EventType e){
    playButton->handleEvent(e);
    if(playButton->isSelected()){
        active = false;
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
            selectedCountry = i;
        }
        
    }
}
void MainMenu::update(){

}

void MainMenu::render(){
    playButton->render();
    renderCountryButtons();
    renderStaticImages();
}

#pragma mark Renders:

void MainMenu::renderStaticImages(){
    output->addSprite("LogoBall", ballX, ballY, ballDimensions.x/2);
    output->addSprite("Logo", logoX, logoY, logoDimensions.x/2);
    output->addSprite("PickTeam", (Constants::GAME_SCREEN_WIDTH - pickTeamDimensions.x)/2, 184, pickTeamDimensions.x);
    output->addSprite("MenuSeparator", (Constants::GAME_SCREEN_WIDTH - separatorDimensions.x)/2, 215, separatorDimensions.x);
}

void MainMenu::renderCountryButtons(){
    Point backSize = output->getSpriteDimensions("CountryBack");
    for(int i = 0;i<5;i++){
        countryButtons[i]->render();
        
        
        string shirtExtension = "Menu";
        string shirtName = countries[i]+shirtExtension;
        Point shirtSize = output->getSpriteDimensions(shirtName);
        
        int shirtToBack = (backSize.x-shirtSize.x)/2;
        int shirtXPos = backMargin + shirtToBack + i*countrySeparation;
        
        int shirtYPos = Constants::GAME_SCREEN_HEIGHT *0.4 + 25;
        int labelXPos = backMargin+i*countrySeparation;
        int labelYPos = shirtYPos +shirtSize.y+ 25;
        string labelExtension = "Label";
        string labelName = countries[i]+labelExtension;
        
        output->addSprite(labelName, labelXPos, labelYPos, backSize.x);
        output->addSprite(shirtName, shirtXPos, shirtYPos, shirtSize.x);
        
        
    }

}

#pragma mark Actions:
bool MainMenu::isActive(){
    return active;
}

int MainMenu::getChosenCountry(){
    return selectedCountry;
}

#pragma mark Delete:

MainMenu::~MainMenu(){
    delete playButton;
    for(int i = 0;i<5;i++){
        delete countryButtons[i];
    }
}
