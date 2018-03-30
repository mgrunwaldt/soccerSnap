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
    Button(Output*o,Input*i,string sprites[3]);
    void setAlphas(int alphas [3]);
    
    void setPosition( int x, int y );
    void handleEvent(EventType e);
    void render();
    
    bool isSelected();
    void setSelected (bool isSelected);
private:
    Point position;
    Input* input;
    Output* output;
    
    bool mouseIsInside();
    bool selected;
    string buttonSprites[3];
    int buttonAlphas[3];
    Point spriteDimensions[3];

    enum ButtonSprite
    {
        MOUSE_OUT = 0,
        MOUSE_OVER = 1,
        MOUSE_DOWN = 2,
    };
    
    ButtonSprite currentSprite;

    
};
#endif /* Button_hpp */
