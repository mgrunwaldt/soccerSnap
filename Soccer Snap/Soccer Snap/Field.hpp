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
    
    bool needsToStart();
    void start();
    
    
    static const int FIELD_X = 280;
    static const int FIELD_Y = 72;
    
private:
    Gem* gems[8][8];
    Gem* firstGem;
    Gem* secondGem;
    Output *output;
    Input* input;
    string player;
    string opponent;
    
    FieldState* state;
    bool selectedGemsAreAdjacent();
    bool canPlaceGem(int x, int y, Gem* gem);
    Gem* getRandomGem();
    Gem* getGemAtMousePosition(Point p);
    vector<vector<int>> toDeleteY;
    vector<Gem*> gemsToDestroy;
    bool makeSwitch();
    void clearGemsToDelete();
    
    void destroyGems();
    
    bool gameNeedsToStart;
    
    
};
#endif /* Field_hpp */
