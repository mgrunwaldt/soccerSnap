//
//  FieldLoading.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/30/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//
#include "Field.hpp"
#include "EventType.hpp"
#include "FieldWaiting.hpp"

FieldState* FieldWaiting::handleInput(EventType e, Field &f){
    if (e == EventType::MouseDown || e == EventType::MouseUp){
        int x, y;
        Point p = f.input->getMousePosition();
        try{
            Gem* clickedGem = f.getGemAtMousePosition(p);
            if (e == EventType::MouseDown){
                if (firstGem == NULL)
                {
                    firstGem = clickedGem;
                    firstGem->setSelected(true);
                }
                else
                {
                    secondGem = clickedGem;
                    secondGem->setSelected(true);
                }
            }
            else if(e == EventType::MouseUp){
                if(firstGem != NULL && firstGem != clickedGem){
                    secondGem = clickedGem;
                    secondGem->setSelected(true);
                }
            }
            
            if (firstGem != NULL && secondGem != NULL)
            {
                if (selectedGemsAreAdjacent())
                {
                    int firstX = firstGem->boardX;
                    int firstY = firstGem->boardY;
                    f.switchGems(firstGem,secondGem);
                    firstGem->switchWithGem(secondGem->boardX, secondGem->boardY);
                    secondGem->switchWithGem(firstX, firstY);
                    FieldSwitchingGems* newState = new FieldSwitchingGems();
                    newState->setGems(firstGem, secondGem);
                    return newState;
                }
                else
                {
                    firstGem->setSelected(false);
                    secondGem->setSelected(true);
                    
                    firstGem = secondGem;
                    secondGem = NULL;
                }
            }

        }
        catch (MouseOutFieldException e){
            if(firstGem!= NULL){
                firstGem->setSelected(false);
                firstGem = NULL;
            }
            if(secondGem != NULL){
                secondGem->setSelected(false);
                secondGem = NULL;
            }
        }
        
    }
    return NULL;
}


FieldState* FieldWaiting::update(Field &f){
    return NULL;
}

void FieldWaiting::render(Field &f){

}

bool FieldWaiting::selectedGemsAreAdjacent(){
    int dx = (int)fabs(firstGem->boardX - secondGem->boardX);
    int dy = (int)fabs(firstGem->boardY - secondGem->boardY);
    
    // if the gems are directly adjacent
    if (dx <= 1 && dy <= 1 && dx + dy == 1)
    {
        return true;
    }
    return false;
}

