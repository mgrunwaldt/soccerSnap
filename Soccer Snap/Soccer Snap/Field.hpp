//
//  Field.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/22/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#ifndef Field_hpp
#define Field_hpp
#include "Output.hpp"
#include "Gem.hpp"
#include "Player.hpp"
#include "Goalkeeper.hpp"
#include "Rival.hpp"
#include "Referee.hpp"
#include "Ball.hpp"


class Field{
public:
    
    Field(Output* o);
    ~Field();
    
    void loadField();
    void drawField();
private:
    Gem* gems[8][8];
    Output *output;
    
    
};
#endif /* Field_hpp */
