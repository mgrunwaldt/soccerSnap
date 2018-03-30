//
//  GameState.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/30/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#ifndef GameState_hpp
#define GameState_hpp

class GameScene;

class GameState
{
public:
    virtual ~GameState() {}
    virtual GameState* handleInput(EventType e, GameScene &g) = 0;
    virtual GameState* update(GameScene &g) =0;
};
#endif /* GameState_hpp */
