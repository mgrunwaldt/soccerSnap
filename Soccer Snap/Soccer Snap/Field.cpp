//
//  Field.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/22/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Field.hpp"

#pragma mark Inicialization

Field::Field(Output* o, Input* i){
    output = o;
    input = i;
}
void Field::load(char* myCountry, char* opponentCountry){
    player = myCountry;
    opponent = opponentCountry;
    firstGem = NULL;
    secondGem = NULL;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            Gem* newGem = getRandomGem();
            while (!canPlaceGem(i, j, newGem)) {
                newGem = getRandomGem();
            }
            newGem->load(output, 65);
            newGem->setPos(i, j);
            newGem->setInitialAnimationPosition();
            gems[i][j] = newGem;
        }
    }
    state = FieldStates::ANIMATING;
}


#pragma mark Game Cycle:
void Field::handleEvent(EventType e){
    if(state == FieldStates::WAITING){
        if (e == EventType::MouseDown || e == EventType::MouseUp)
        {
            int x, y;
            Point p = input->getMousePosition();
            try{
                Gem* clickedGem = getGemAtMousePosition(p);
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
                        state = FieldStates::PREPARING_FIRST_SWITCH;
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
            catch (MouseOutFieldException* e){
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
    }
}

void Field::update(){
    if(state == FieldStates::ANIMATING){
        bool allOk = true;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                Gem* toDraw = gems[i][j];
                toDraw->update();
                if(!toDraw->isInPlace())
                    allOk = false;
            }
        }
        if(allOk){
            state = FieldStates::WAITING;
        }
    }
    else if (state == FieldStates::WAITING){
    
    }
    else if(state == FieldStates::PREPARING_FIRST_SWITCH){
        int firstX = firstGem->boardX;
        int firstY = firstGem->boardY;
        gems[firstGem->boardX][firstGem->boardY] = secondGem;
        gems[secondGem->boardX][secondGem->boardY] = firstGem;
        firstGem->switchWithGem(secondGem->boardX, secondGem->boardY);
        secondGem->switchWithGem(firstX, firstY);
        
        state = SWITCHING;
    }
    else if(state == FieldStates::SWITCHING){
        firstGem->setSelected(false);
        secondGem->setSelected(false);
        firstGem->update();
        secondGem->update();
        if(!firstGem->isSwitching() && !secondGem->isSwitching()){
            if(makeSwitch()){
                state = FieldStates::PREPARING_DESTRUCTION;
                //borrar, llenar, animar, makeswitch
            }
            else{
                int firstX = firstGem->boardX;
                int firstY = firstGem->boardY;
                gems[firstGem->boardX][firstGem->boardY] = secondGem;
                gems[secondGem->boardX][secondGem->boardY] = firstGem;
                firstGem->switchWithGem(secondGem->boardX, secondGem->boardY);
                secondGem->switchWithGem(firstX, firstY);
                
                state = FieldStates::SWITCHING_BACK;
            }
            
        }
    }
    else if(state == SWITCHING_BACK){
        firstGem->update();
        secondGem->update();
        if(!firstGem->isSwitching() && !secondGem->isSwitching()){
            state = FieldStates::WAITING;
            firstGem = NULL;
            secondGem = NULL;
        }
    }
    else if(state == PREPARING_DESTRUCTION){
        destroyGems();
    }
    else if(state == DESTROYING){
        for(int i = 0;i < gemsToDestroy.size(); i++){
            gemsToDestroy[i]->update();
        }
    }
    else if (state == GEMS_GOING_DOWN){
        bool isGoingDown = false;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                Gem* toDraw = gems[i][j];
                toDraw->update();
                if(toDraw->isGoingDown()){
                    isGoingDown = true;
                }
            }
        }
        if(!isGoingDown){
            if(makeSwitch()){
                state = FieldStates::PREPARING_DESTRUCTION;
                //borrar, llenar, animar, makeswitch
            }
            
            else state = WAITING;//mentira, chequar de nuevo
        }
        /*bool isGoingDown = false;
        for(int i = 0;i < gemsToDestroy.size(); i++){
            gemsToDestroy[i]->update();
            if(gemsToDestroy[i]->isGoingDown()){
                isGoingDown = true;
            }
        }
        if(!isGoingDown){
            state = WAITING;//mentira, chequar de nuevo
        }*/
    }
    
    

}





void Field::render(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            Gem* toDraw = gems[i][j];
            toDraw->render();
        }
    }
    if(state == DESTROYING){
        bool keepsDestroying = false;
        for(int i = 0;i < gemsToDestroy.size(); i++){
            gemsToDestroy[i]->render();
            if(gemsToDestroy[i]->needsDelete()){
                //keepsDestroying = true;
            }
        }
        if(!keepsDestroying){
            state = GEMS_GOING_DOWN;
            for(int i = 0;i < gemsToDestroy.size(); i++){
                delete gemsToDestroy[i];
            }
            gemsToDestroy.clear();
        }
    }
}

#pragma mark Game Logic:
void Field::clearGemsToDelete(){
    for(int i=0;i<toDeleteY.size();i++){
        toDeleteY[i].clear();
    }
    toDeleteY.clear();
}


Gem* Field::getGemAtMousePosition(Point p){
    for(int i = 0;i<8;i++){
        for (int j = 0;j<8;j++){
            if(gems[i][j]->hasMouseInside(p)){
                return gems[i][j];
            }
        }
    }
    throw new MouseOutFieldException;
}



bool Field::canPlaceGem(int x, int y, Gem* gem)
{
    if(y>=2){
        if(gems[x][y-2]->getType() == gems[x][y-1]->getType() && gems[x][y-1]->getType() == gem->getType())
            return false;
    }
    
    if(x>=2){
        if(gems[x-2][y]->getType() == gems[x-1][y]->getType() && gems[x-1][y]->getType() == gem->getType())
            return false;
    }
    return true;
}

bool Field::selectedGemsAreAdjacent(){
    int dx = (int)fabs(firstGem->boardX - secondGem->boardX);
    int dy = (int)fabs(firstGem->boardY - secondGem->boardY);
    
    // if the gems are directly adjacent
    if (dx <= 1 && dy <= 1 && dx + dy == 1)
    {
        return true;
    }return false;
}

Gem* Field::getRandomGem(){
    Gem* newGem;
    int randNum = rand()%(5) + 1;
    switch (randNum) {
        case 1:
            newGem = new Player();//pasar aca el spriteName
            newGem->setSprite(player);
            break;
        case 2:
            newGem = new Rival();
            newGem->setSprite(opponent);
            break;
        case 3:
            newGem = new Goalkeeper();
            break;
        case 4:
            newGem = new Referee();
            break;
            
        default:
            newGem = new Ball();
            break;
    }
    return newGem;
}

void Field::destroyGems(){
    for(int x = 0;x<8;x++){
        std::vector<int> columnToDelete = toDeleteY[x];
        if(columnToDelete.size() > 0){
            for(int y = 7; y>=0; y--){
                if(gems[x][y]->needsDelete()){
                    gemsToDestroy.push_back(gems[x][y]);
                }
                std::sort(columnToDelete.begin(), columnToDelete.end(), std::greater<int>());

                int yToDelete = columnToDelete.front();
                
                if(y < yToDelete && !gems[x][y]->needsDelete()){
                    
                    gems[x][yToDelete] = gems[x][y];
                    gems[x][yToDelete]->setNextPos(yToDelete);
                    //cambiar posicion de x, ytodelete
                    //gems[x][yToDelete]->setPos(x, yToDelete);
                    //era prueba
                    columnToDelete.erase(columnToDelete.begin());
                    columnToDelete.push_back(y);

                }
                
            }
            int remainingCounter = 0;
            while (!columnToDelete.empty()) {
                int yToFill = columnToDelete.front();
                Gem* newGem = getRandomGem();
                newGem->load(output, 65);
                newGem->setPos(x, remainingCounter-1);
                newGem->setNextPos(yToFill);
                gems[x][yToFill] = newGem;
                
                columnToDelete.erase(columnToDelete.begin());
                remainingCounter--;
            }
            toDeleteY[x].clear();
        }
        
    }
    state = FieldStates::DESTROYING;
}

bool Field::makeSwitch(){//Falta inicializar toDeleteY??
    clearGemsToDelete();
    bool switchMade = false;
    for(int x = 0;x<8;x++){
        std::vector<int> columnToDelete;
        
        int currentY = 0;
        while (currentY<8){
            bool nextIsEqual = true;
            int equalsInARow = 1;
            int next = currentY+1;
            Gem*currentGem = gems[x][currentY];
            while (next<8 && nextIsEqual) {
                Gem* nextGem = gems[x][next];
                if(nextGem->getType() == currentGem->getType()){
                    next++;
                    equalsInARow++;
                }
                else nextIsEqual = false;
            }
            if(equalsInARow >=3){
                switchMade = true;
                for (int yToAdd = currentY; yToAdd<currentY+equalsInARow;yToAdd++){
                    gems[x][yToAdd]->setDeleted();
                    columnToDelete.push_back(yToAdd);
                }
            }
            currentY += equalsInARow;
        }
        toDeleteY.push_back(columnToDelete);
        //clear columnToDelete?
    }
    for(int y = 0;y<8;y++){
        int currentX = 0;
        while (currentX<8){
            
            bool nextIsEqual = true;
            int equalsInARow = 1;
            int next = currentX+1;
            Gem*currentGem = gems[currentX][y];
            while (next<8 && nextIsEqual) {
                Gem* nextGem = gems[next][y];
                if(nextGem->getType() == currentGem->getType()){
                    next++;
                    equalsInARow++;
                }
                else nextIsEqual = false;
            }
            if(equalsInARow >=3){//FALTA NO AGREGAR DUPLICADOS!!!
                switchMade = true;
                for (int xToAdd = currentX; xToAdd<currentX+equalsInARow;xToAdd++){
                    std::vector<int> columnToDelete = toDeleteY[xToAdd];
                    gems[xToAdd][y] ->setDeleted();
                    if (std::find(columnToDelete.begin(), columnToDelete.end(),y)==columnToDelete.end()){
                        columnToDelete.push_back(y);
                        toDeleteY[xToAdd] = columnToDelete;
                        
                    }
                }
            }
            //Hay que agregar a toDelete?
            currentX += equalsInARow;
        }
    }
    return switchMade;
}

