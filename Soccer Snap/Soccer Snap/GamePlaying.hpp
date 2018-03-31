//
//  GamePlaying.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/30/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "GameState.hpp"

#ifndef GamePlaying_hpp
#define GamePlaying_hpp

class GamePlaying : public GameState
{
public:
    //agregar metodos que solo sirvan en este estado
    GameState* handleInput(EventType e, GameScene &g);
    GameState* update (GameScene &g);
    void render(GameScene &g);

private:
};
#endif /* GamePlaying_hpp */
