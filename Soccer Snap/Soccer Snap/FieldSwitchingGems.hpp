//
//  FieldSwitchingGems.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/31/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "FieldState.hpp"
#ifndef FieldSwitchingGems_hpp
#define FieldSwitchingGems_hpp

class FieldSwitchingGems : public FieldState
{
public:
    //agregar metodos que solo sirvan en este estado
    
    FieldState* handleInput(EventType e, Field &f);
    FieldState* update (Field &f);
    void render (Field &f);
    
    void setGems(Gem* gem1, Gem* gem2);
    
private:
    Gem* firstGem;
    Gem* secondGem;
    

    

};
#endif /* FieldSwitchingGems_hpp */
