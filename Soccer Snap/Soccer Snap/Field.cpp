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
void Field::loadField(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            Gem* newGem;
            int randNum = rand()%(5) + 1;
            
            switch (randNum) {
                case 1:
                    newGem = new Player();//pasar aca el spriteName
                    newGem->setSprite("Uruguay");
                    newGem->load(output, 104);
                    break;
                case 2:
                    newGem = new Player();
                    newGem->setSprite("Portugal");
                    newGem->load(output, 104);
                    break;
                case 3:
                    newGem = new Goalkeeper();
                    newGem->load(output, 104);
                    break;
                case 4:
                    newGem = new Referee();
                    newGem->load(output, 104);
                    break;
                    
                default:
                    newGem = new Ball();
                    newGem->load(output, 104);
                    break;
            }
            newGem->setPos(i, j);
            gems[i][j] =newGem;

        }
    }
}

void Field::drawField(){
    output->addSprite("Field_lvl1", 2*280, 2*72, 2*512);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            Gem* toDraw = gems[i][j];
            toDraw->draw();
        }
    }
}
