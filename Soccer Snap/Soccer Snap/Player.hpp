//
//  Player.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/22/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include "Gem.hpp"

class Player: public Gem{
    
    
public:
    void load(Output* output, int w, int h=0);
    char* getType();
private:
   
};

#endif /* Player_hpp */
