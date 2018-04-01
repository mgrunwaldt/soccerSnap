//
//  FieldLoading.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/30/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//
#include "FieldState.hpp"
#include "Gem.hpp"

#ifndef Field_Waiting_hpp
#define Field_Waiting_hpp

class FieldWaiting : public FieldState
{
public:
    //agregar metodos que solo sirvan en este estado
    FieldState* handleInput(EventType e, Field &f);
    FieldState* update (Field &f);
    void render (Field &f);
    
private:
    Gem* firstGem;
    Gem* secondGem;
    bool selectedGemsAreAdjacent();
    
};
#endif /* FieldWaiting_hpp */
