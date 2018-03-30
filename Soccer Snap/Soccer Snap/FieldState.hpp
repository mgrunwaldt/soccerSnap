//
//  FieldState.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/30/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#ifndef FieldState_hpp
#define FieldState_hpp

class Field;

class FieldState
{
public:
    virtual ~FieldState() {}
    virtual FieldState* handleInput(EventType e, Field &f) = 0;
    virtual FieldState* update(Field &f) =0;
};
#endif /* FieldState_hpp */

