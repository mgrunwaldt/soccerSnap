//
//  Field.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/22/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Field.hpp"

Field::Field(Output* o){
    output = o;
}
void Field::load(char* myCountry, char* opponentCountry){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            Gem* newGem;//esta mal, tiene que ser de c/u
            int randNum = rand()%(5) + 1;
            
            switch (randNum) {
                case 1:
                    newGem = new Player();//pasar aca el spriteName
                    newGem->setSprite(myCountry);
                    newGem->load(output, 65);
                    break;
                case 2:
                    newGem = new Player();
                    newGem->setSprite(opponentCountry);
                    newGem->load(output, 65);
                    break;
                case 3:
                    newGem = new Goalkeeper();
                    newGem->load(output, 65);
                    break;
                case 4:
                    newGem = new Referee();
                    newGem->load(output, 65);
                    break;
                    
                default:
                    newGem = new Ball();
                    newGem->load(output, 65);
                    break;
            }
            newGem->setPos(i, j);
            newGem->setInitialAnimationPosition();
            gems[i][j] = newGem;

        }
    }
}

void Field::update(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            Gem* toDraw = gems[i][j];
            toDraw->update();
        }
    }
   // Gem* toDraw = gems[0][0];
    //toDraw->update();
    //00 01 02 03 10 11 12 13
}

void Field::render(){
  //  output->addSprite("Field_lvl1", FIELD_X, FIELD_Y, FIELD_WIDTH);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            Gem* toDraw = gems[i][j];
            toDraw->render();
        }
    }
    //Gem* toDraw = gems[0][0];
    //toDraw->render();
    
}

void Field::mouseDown(Point p){

}

void Field::mouseUp(Point p){
    
}
