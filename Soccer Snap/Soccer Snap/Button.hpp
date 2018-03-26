//
//  Button.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/25/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//
#include "Input.hpp"
#include "Output.hpp"
#include "EventType.hpp"
#include "Point.hpp"

#ifndef Button_hpp
#define Button_hpp

class Button{

    
public:
    //Initializes internal variables
    Button(Output*o,Input*i,char* sprites[3]);
    
    //Sets top left position
    void setPosition( int x, int y );
    
    //Handles mouse event
    void handleEvent(EventType e);
    
    //Shows button sprite
    void render();
    
    void setAlphas(int alphas [3]);
    
    
private:
    //Top left position
    Point position;
    Input* input;
    Output* output;
    
    bool mouseIsInside();
    char* buttonSprites[3];
    int buttonAlphas[3];
    Point spriteDimensions[3];

    //Currently used global sprite
    enum ButtonSprite
    {
        MOUSE_OUT = 0,
        MOUSE_OVER = 1,
        MOUSE_DOWN = 2,
    };
    
    ButtonSprite currentSprite;

    
};
#endif /* Button_hpp */
