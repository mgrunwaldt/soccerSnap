//
//  GameFinished.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/30/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "GameState.hpp"

#ifndef GameFinished_hpp
#define GameFinished_hpp

class GameFinished : public GameState
{
public:
    //agregar metodos que solo sirvan en este estado
    GameState* handleInput(EventType e, GameScene &g);
    GameState* update (GameScene &g);
    void render(GameScene &g);

private:
    int boardY = Constants::GAME_SCREEN_HEIGHT;
    Point boardSize;
    Button* playAgainButton;
    Button* homeButton;
    bool boardUp = false;
    bool buttonsInitialized = false;
};

#endif /* GameFinished_hpp */


