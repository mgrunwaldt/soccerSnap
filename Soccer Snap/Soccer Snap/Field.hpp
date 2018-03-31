//
//  Field.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/22/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#ifndef Field_hpp
#define Field_hpp
#include "Output.hpp"
#include "Input.hpp"
#include "Gem.hpp"
#include "Point.hpp"
#include "EventType.hpp"
#include "MouseOutFieldException.hpp"
#include <vector>
#include <ctime>
#include <cstdlib>

#include "FieldState.hpp"
#include "FieldWaiting.hpp"
#include "FieldAnimating.hpp"
#include "FieldSwitchingGems.hpp"
#include "FieldDestroyingGems.hpp"
#include "FieldGemsGoingDown.hpp"

/*
enum FieldStates
{
    WAITING,
    ANIMATING,
    PREPARING_FIRST_SWITCH,
    SWITCHING,
    SWITCHING_BACK,
    PREPARING_DESTRUCTION,
    DESTROYING,
    GEMS_GOING_DOWN,
};*/

class Field{
public:
    
    Field(Output* o, Input* i);
    ~Field();
    
    void load(string myCountry, string opponentCountry);
    void handleEvent(EventType e);
    void update();
    void render();
    
    void setReadyToStart();
    bool isReadyToStart();
    bool moveGems();
    void skipLoader();
    
    
    static const int FIELD_X = 280;
    static const int FIELD_Y = 72;
    
    void switchGems(Gem* firstGem, Gem* secondGem);
    void setGemAtPos(Gem* gem, int x, int y);
    
    Input* input;
    Gem* getGemAtMousePosition(Point p);
    Gem* getGem(int x, int y);
    Gem* getRandomGem();
    
    bool makeSwitch();
    void clearGemsToDelete();
    void destroyGems();
    vector<Gem*> gemsToDestroy;

private:
    Gem* gems[Constants::GEMS_PER_ROW][Constants::GEMS_PER_ROW];
    void loadInitialMap();
   // Gem* firstGem;
   // Gem* secondGem;
    Output *output;
    
    string player;
    string opponent;
    
    FieldState* state;
    bool canPlaceGem(int x, int y, Gem* gem);
    vector<vector<int>> toDeleteY;
    
    
    
    
    
    bool readyToStart;
    
    
};
#endif /* Field_hpp */
