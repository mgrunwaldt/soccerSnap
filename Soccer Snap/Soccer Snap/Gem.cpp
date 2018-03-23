//
//  Gem.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/21/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Gem.hpp"
static int fieldX = 2*280;
static int fieldY = 2*72;
static int separation = 2*12;
Gem::~Gem(){
    
}

void Gem::setSprite(char* countryName){
    spriteName = countryName;
}

void Gem::load(Output*output, int w, int h){
    outputFacade = output;
    width = w;
    height = h;
    x= 200;
    y= 100;
}

void Gem::setPos(int gridX, int gridY){
    x = 12+fieldX+gridX*(separation+width);
    y = 12+fieldY+gridY*(separation+width);
}
void Gem::draw(){
    outputFacade->addSprite(spriteName, x, y, width, height);
}

void Gem::update(){
    x++;
}
void Gem::clean(){

}
