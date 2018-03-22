//
//  Field.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/22/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#ifndef Field_hpp
#define Field_hpp

#include "Game.hpp"
#include "Gem.hpp"

class Field{
public:
    
    Field();
    ~Field();
    
    void LoadField();
    void DrawField();
private:
    Gem* field[8][8];
    
    
};
#endif /* Field_hpp */
