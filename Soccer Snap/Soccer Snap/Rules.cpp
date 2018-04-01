//
//  Rules.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 4/1/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Rules.hpp"


#pragma mark Initialization:

Rules::Rules(Output* o, Input* i){
    output = o;
    input = i;
    active = true;
}
void Rules::load(){
    string menuButtonSprites[3]={"MenuButtonOut","MenuButtonOver","MenuButtonIn"};
    homeButton = new Button(output,input,menuButtonSprites);
    homeButton->setPosition(25, 25);
}


#pragma mark Game Cycle:

void Rules::handleEvent(EventType e){
    homeButton->handleEvent(e);
    if(homeButton->isSelected()){
        active = false;
    }
}

void Rules::update(){

}

void Rules::render(){
    Point rulesWidth = output->getSpriteDimensions("rules");
    output->addSprite("Rules", 0, 0, rulesWidth.x);
    homeButton->render();
}

bool Rules::isActive(){
    return active;
}

#pragma mark Destructor:

Rules::~Rules(){
    delete homeButton;
}
/*

 ~Rules();
 
 void handleEvent(EventType e);
 void update();
 void render();
 
 bool isActive();
 
 private:
 Output *output;
 Input * input;
 
 
 bool animating;
 Button* homeButton;
 */
