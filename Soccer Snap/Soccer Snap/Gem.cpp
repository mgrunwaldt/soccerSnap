//
//  Gem.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/21/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Gem.hpp"
static int fieldX = 280;
static int fieldY = 72;
static int separation = 12;
Gem::~Gem(){
    
}

void Gem::setSprite(char* countryName){
    spriteName = countryName;
}

void Gem::load(Output*output, int w, int h){
    outputFacade = output;
    width = w;
    height = h;
}

void Gem::setPos(int gridX, int gridY){
    
    x = 6+fieldX+gridX*(separation+width);
    y = 6+fieldY+gridY*(separation+width);
}
void Gem::draw(){
    outputFacade->addSprite(spriteName, x, y, width, height);
}

void Gem::update(){
    x++;
}
void Gem::clean(){

}
