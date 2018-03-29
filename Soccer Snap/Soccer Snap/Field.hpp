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
#include "Player.hpp"
#include "Goalkeeper.hpp"
#include "Rival.hpp"
#include "Referee.hpp"
#include "Ball.hpp"
#include "Point.hpp"
#include "EventType.hpp"
#include <exception>
#include <vector>

struct MouseOutFieldException : public std::exception
{
    const char * message () const throw ()
    {
        return "Mouse Outside Field";
    }
};


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
    Filling,
};

class Field{
public:
    
    Field(Output* o, Input* i);
    ~Field();
    
    void load(char* myCountry, char*opponentCountry);
    void handleEvent(EventType e);
    void update();
    void render();
    
    
    static const int FIELD_X = 280;
    static const int FIELD_Y = 72;
    static const int FIELD_WIDTH = 512;
private:
    Gem* gems[8][8];
    Gem* firstGem;
    Gem* secondGem;
    Output *output;
    Input* input;
    char* player;
    char* opponent;
    
    FieldStates state;
    bool selectedGemsAreAdjacent();
    bool canPlaceGem(int x, int y, Gem* gem);
    Gem* getRandomGem();
    Gem* getGemAtMousePosition(Point p);
    std::vector<std::vector<int>> toDeleteY;
    std::vector<Gem*> gemsToDestroy;
    bool makeSwitch();
    void clearGemsToDelete();
    
    void destroyGems();
    
};
#endif /* Field_hpp */
