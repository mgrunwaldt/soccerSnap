//
//  Field.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/22/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Field.hpp"
#include "GameScene.hpp"

#pragma mark Inicialization

Field::Field(Output* o, Input* i, GameScene* parent){
    output = o;
    input = i;
    game = parent;
}
void Field::load(string myCountry, string opponentCountry){
    player = myCountry;
    opponent = opponentCountry;

    readyToStart = false;
    srand(time(NULL));
    loadInitialMap();
    state = new FieldAnimating();
}

void Field::loadInitialMap(){
    for(int i=0;i<Constants::GEMS_PER_ROW;i++){
        for(int j=0;j<Constants::GEMS_PER_ROW;j++){
            Gem* newGem = getRandomGem();
            while (!canPlaceGem(i, j, newGem)) {
                newGem = getRandomGem();
            }
            newGem->load(output);
            newGem->setPos(i, j);
            newGem->setInitialAnimationPosition();
            gems[i][j] = newGem;
        }
    }
}

#pragma mark Game Cycle:

void Field::handleEvent(EventType e){
    FieldState* newState = state->handleInput(e,*this);
    if(newState != NULL){
        delete state;
        state = newState;
    }
}

void Field::update(){
    FieldState* newState = state->update(*this);
    if(newState != NULL){
        delete state;
        state = newState;
    }
}

void Field::render(){
    for(int i=0;i<Constants::GEMS_PER_ROW;i++){
        for(int j=0;j<Constants::GEMS_PER_ROW;j++){
            Gem* toDraw = gems[i][j];
            toDraw->render();
        }
    }
    state->render(*this);
}

#pragma mark State Actions:

bool Field::moveGems(){
    bool allOk = true;
    for(int i=0;i<Constants::GEMS_PER_ROW;i++){
        for(int j=0;j<Constants::GEMS_PER_ROW;j++){
            Gem* toDraw = gems[i][j];
            toDraw->update();
            if(toDraw->isMoving())
                allOk = false;
        }
    }
    return allOk;
}

void Field::skipLoader(){
    for(int i=0;i<Constants::GEMS_PER_ROW;i++){
        for(int j=0;j<Constants::GEMS_PER_ROW;j++){
            Gem* toDraw = gems[i][j];
            toDraw->setPos(i,j);
            toDraw->setMoving(false);
        }
    }
}

void Field::addTime (int seconds){
    game->addTime(seconds);
}
void Field::addOpponentPoints (int points){
    game->addOpponentPoints(points);
}
void Field::addPoints (int points){
    game->addPoints(points);
}

#pragma mark Game Logic:

void Field::switchGems(Gem* firstGem, Gem* secondGem){
    gems[firstGem->boardX][firstGem->boardY] = secondGem;
    gems[secondGem->boardX][secondGem->boardY] = firstGem;
}

void Field::setGemAtPos(Gem* gem, int x, int y){
    gems[x][y] = gem;
}

Gem* Field::getGemAtMousePosition(Point p){
    for(int i = 0;i<Constants::GEMS_PER_ROW;i++){
        for (int j = 0;j<Constants::GEMS_PER_ROW;j++){
            if(gems[i][j]->hasMouseInside(p)){
                return gems[i][j];
            }
        }
    }
    MouseOutFieldException ex;
    throw ex;
}

Gem* Field::getRandomGem(){
    Gem* newGem;
    int randNum = rand()%(5) + 1;
    switch (randNum) {
        case 1:
            newGem = new Gem(player);
            break;
        case 2:
            newGem = new Gem(opponent);
            newGem->setOpponent();
            break;
        case 3:
            newGem = new Gem("Goalkeeper");
            break;
        case 4:
            newGem = new Gem("Referee");
            break;
            
        default:
            newGem = new Gem("Ball");
            break;
    }
    newGem->load(output);
    return newGem;
}

Gem* Field::getGem(int x, int y){
    return gems[x][y];
}


#pragma mark Conditions:

void Field::setReadyToStart(){
    readyToStart = true;
}

bool Field::isReadyToStart(){
    return readyToStart;
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


#pragma mark Gem Destruction:
void Field::addToCorrispondingPattern (Gem* gem, int sequenceSize){
    if(sequenceSize == 3){
        gemsBy3.push_back(gem);
    }
    else if(sequenceSize == 4){
        gemsBy4.push_back(gem);
    }
    else{
        gemsBy5.push_back(gem);
    }
}

void Field::createTPattern(int xToAdd, int y, int equalsInARow){
    bool leftDone = false;
    int previousX = xToAdd-1;
    while (previousX>=0 && !leftDone) {
        if(getGem(previousX, y)->getType() == getGem(xToAdd, y)->getType()){
            removeFromCorrispondingPattern(getGem(previousX, y));
            gemsByT.push_back(getGem(previousX, y));
        }
        else leftDone = true;
        previousX--;
    }
    int nextX = xToAdd + 1;
    int rightDone = false;
    while (nextX<Constants::GEMS_PER_ROW && !rightDone) {
        if(getGem(nextX, y)->getType() == getGem(xToAdd, y)->getType()){
            vector<int> columnToDelete = toDeleteY[nextX];
            gemsByT.push_back(getGem(nextX, y));
            columnToDelete.push_back(y);
            toDeleteY[nextX] = columnToDelete;
        }
        else rightDone = true;
        nextX++;
    }
    bool topDone = false;
    bool bottomDone = false;
    int previousY = y-1;
    int nextY = y+1;
    while (previousY>=0 && !topDone) {
        if(getGem(xToAdd, previousY)->getType() == getGem(xToAdd, y)->getType()){
            removeFromCorrispondingPattern(getGem(xToAdd, previousY));
            gemsByT.push_back(getGem(xToAdd, previousY));
        }
        else topDone = true;
        previousY--;
    }
    while (nextY<Constants::GEMS_PER_ROW && !bottomDone) {
        if(getGem(xToAdd, nextY)->getType() == getGem(xToAdd, y)->getType()){
            removeFromCorrispondingPattern(getGem(xToAdd, nextY));
            gemsByT.push_back(getGem(xToAdd, nextY));
        }
        else bottomDone = true;
        nextY++;
    }
    removeFromCorrispondingPattern(getGem(xToAdd, y));
    gemsByT.push_back(getGem(xToAdd, y));//en el y lo agregue a equals in a row con 4, ahora con x equals in a row es 3, no lo va a sacar
}

void Field::removeFromCorrispondingPattern (Gem* gem){
    if (find(gemsBy3.begin(), gemsBy3.end(),gem)!=gemsBy3.end()){
        int posToDelete = find(gemsBy3.begin(),gemsBy3.end(),gem)-gemsBy3.begin();
        gemsBy3.erase(gemsBy3.begin()+ posToDelete);
    }
    else if (find(gemsBy4.begin(), gemsBy4.end(),gem)!=gemsBy4.end()){
        int posToDelete = find(gemsBy4.begin(),gemsBy4.end(),gem)-gemsBy4.begin();
        gemsBy4.erase(gemsBy4.begin()+ posToDelete);
    }
    else if (find(gemsBy5.begin(), gemsBy5.end(),gem)!=gemsBy5.end()){
        int posToDelete = find(gemsBy5.begin(),gemsBy5.end(),gem)-gemsBy5.begin();
        gemsBy5.erase(gemsBy5.begin()+ posToDelete);
    }
}

bool Field::makeSwitch(){
    clearGemsToDelete();
    bool switchMade = false;
    for(int x = 0;x<Constants::GEMS_PER_ROW;x++){
        vector<int> columnToDelete;
        
        int currentY = 0;
        while (currentY<Constants::GEMS_PER_ROW){
            bool nextIsEqual = true;
            int equalsInARow = 1;
            int next = currentY+1;
            Gem*currentGem = getGem(x, currentY);
            while (next<Constants::GEMS_PER_ROW && nextIsEqual) {
                Gem* nextGem = getGem(x, next);
                if(nextGem->getType() == currentGem->getType()){
                    next++;
                    equalsInARow++;
                }
                else nextIsEqual = false;
            }
            if(equalsInARow >=3){
                switchMade = true;
                for (int yToAdd = currentY; yToAdd<currentY+equalsInARow;yToAdd++){
                    getGem(x, yToAdd)->setDeleted();
                    columnToDelete.push_back(yToAdd);
                    addToCorrispondingPattern(getGem(x, yToAdd), equalsInARow);
                }
            }
            currentY += equalsInARow;
        }
        toDeleteY.push_back(columnToDelete);
    }
    for(int y = 0;y<Constants::GEMS_PER_ROW;y++){
        int currentX = 0;
        while (currentX<Constants::GEMS_PER_ROW){
            
            bool nextIsEqual = true;
            int equalsInARow = 1;
            int next = currentX+1;
            Gem*currentGem = getGem(currentX, y);
            while (next<Constants::GEMS_PER_ROW && nextIsEqual) {
                Gem* nextGem = getGem(next, y);
                if(nextGem->getType() == currentGem->getType()){
                    next++;
                    equalsInARow++;
                }
                else nextIsEqual = false;
            }
            if(equalsInARow >=3){
                switchMade = true;
                for (int xToAdd = currentX; xToAdd<currentX+equalsInARow;xToAdd++){
                    vector<int> columnToDelete = toDeleteY[xToAdd];
                    getGem(xToAdd, y) ->setDeleted();
                    if (find(columnToDelete.begin(), columnToDelete.end(),y)==columnToDelete.end()){
                        columnToDelete.push_back(y);
                        toDeleteY[xToAdd] = columnToDelete;
                        addToCorrispondingPattern(getGem(xToAdd, y), equalsInARow);
                    }
                    else{
                        createTPattern(xToAdd, y, equalsInARow);
                        break;
                    }
                }
            }
            currentX += equalsInARow;
        }
    }
    return switchMade;
}


void Field::clearGemsToDelete(){
    for(int i=0;i<toDeleteY.size();i++){
        toDeleteY[i].clear();
    }
    toDeleteY.clear();
    gemsBy3.clear();
    gemsBy4.clear();
    gemsBy5.clear();
    gemsByT.clear();
}

void Field::destroyGems(){
    gemsToDestroy.clear();
    for(int x = 0;x<Constants::GEMS_PER_ROW;x++){
        vector<int> columnToDelete = toDeleteY[x];
        if(columnToDelete.size() > 0){
            for(int y = Constants::GEMS_PER_ROW-1; y>=0; y--){
                if(getGem(x, y)->needsDelete()){
                    gemsToDestroy.push_back(getGem(x, y));
                }
                sort(columnToDelete.begin(), columnToDelete.end(), greater<int>());
                
                int yToDelete = columnToDelete.front();
                
                if(y < yToDelete && !getGem(x, y)->needsDelete()){
                    
                    setGemAtPos(getGem(x, y), x, yToDelete);
                    getGem(x,yToDelete)->setNextPos(yToDelete);
                    columnToDelete.erase(columnToDelete.begin());
                    columnToDelete.push_back(y);
                    
                }
                
            }
            int remainingCounter = 0;
            while (!columnToDelete.empty()) {
                int yToFill = columnToDelete.front();
                Gem* newGem = getRandomGem();
                newGem->setPos(x, remainingCounter-1);
                newGem->setNextPos(yToFill);
                setGemAtPos(newGem, x, yToFill);
                
                columnToDelete.erase(columnToDelete.begin());
                remainingCounter--;
            }
            toDeleteY[x].clear();
        }
        
    }
}

#pragma mark Destructor:

Field::~Field(){
    delete state;
}
