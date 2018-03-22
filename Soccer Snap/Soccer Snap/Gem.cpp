//
//  Gem.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/21/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Gem.hpp"

Gem::~Gem(){
    
}

void Gem::load(Output*output, char* sprite, int w, int h){
    spriteName = sprite;
    outputFacade = output;
    width = w;
    height = h;
    x= 200;
    y= 100;
}

void Gem::draw(){
    outputFacade->addSprite(spriteName, x, y, width, height);
}

void Gem::update(){
    x++;
}
void Gem::clean(){

}
