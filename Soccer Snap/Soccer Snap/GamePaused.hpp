//
//  GamePaused.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/30/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//
#include "GameState.hpp"

#ifndef GamePaused_hpp
#define GamePaused_hpp


class GamePaused : public GameState
{
public:
    //agregar metodos que solo sirvan en este estado
    GameState* handleInput(EventType e, GameScene &g);
    GameState* update (GameScene &g);
    
private:
};

#endif /* GamePaused_hpp */
