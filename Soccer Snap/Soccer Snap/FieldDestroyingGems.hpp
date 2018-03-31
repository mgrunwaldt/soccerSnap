//
//  FieldDestroyingGems.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/31/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//
#include "FieldState.hpp"

#ifndef FieldDestroyingGems_hpp
#define FieldDestroyingGems_hpp

class FieldDestroyingGems : public FieldState
{
public:
    //agregar metodos que solo sirvan en este estado
    FieldState* handleInput(EventType e, Field &f);
    FieldState* update (Field &f);
    void setGemsToDestroy (vector<Gem*> gems);
    void render (Field &f);
private:
    vector<Gem*> gemsToDestroy;

};

#endif /* FieldDestroyingGems_hpp */
