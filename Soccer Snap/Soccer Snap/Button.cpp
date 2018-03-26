//
//  Button.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/25/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Button.hpp"

#pragma mark Setup

Button::Button(Output* o, Input* i,char* sprites[3])
{
    position.x = 0;
    position.y = 0;
    
    output = o;
    input = i;
    for(int i = 0;i<3;i++){
        buttonSprites[i] = sprites[i];
        Point spriteSize = output->getSpriteDimensions(sprites[i]);
        spriteDimensions[i] = spriteSize;
        buttonAlphas[i] = 255;
    }
    currentSprite = MOUSE_OUT;
}

void Button::setPosition( int x, int y )
{
    position.x = x;
    position.y = y;
}

void Button::setAlphas(int alphas[3]){
    for(int i = 0;i<3;i++){
        buttonAlphas[i] = alphas[i];
    }
}
#pragma mark Events

void Button::handleEvent(EventType e )
{
    if(e == EventType::MouseMotion || e == EventType::MouseUp || e == EventType::MouseDown){
        if(!mouseIsInside()){
            currentSprite = MOUSE_OUT;
        }
        else{
            if(e == EventType::MouseDown){
                currentSprite = MOUSE_DOWN;
            }
            else currentSprite = MOUSE_OVER;
        }
        
    }
    

}
bool Button::mouseIsInside(){
    Point mousePosition = input->getMousePosition();
    
    //Mouse is left of the button
    if( mousePosition.x < position.x || mousePosition.x > position.x + spriteDimensions[currentSprite].x ||mousePosition.y < position.y||mousePosition.y > position.y + spriteDimensions[currentSprite].y )
    {
        return false;
    }
    return true;
}

#pragma mark Render

void Button::render(){
    output->addSprite(buttonSprites[currentSprite], position.x, position.y, spriteDimensions[currentSprite].x, spriteDimensions[currentSprite].y,0,buttonAlphas[currentSprite]);
}
