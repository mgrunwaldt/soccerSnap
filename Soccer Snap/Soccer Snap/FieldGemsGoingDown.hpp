//
//  FieldGemsGoingDown.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/31/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "FieldState.hpp"
#ifndef FieldGemsGoingDown_hpp
#define FieldGemsGoingDown_hpp

class FieldGemsGoingDown : public FieldState
{
public:
    FieldState* handleInput(EventType e, Field &f);
    FieldState* update (Field &f);
    void render (Field &f);
    
private:
};

#endif /* FieldGemsGoingDown_hpp */
