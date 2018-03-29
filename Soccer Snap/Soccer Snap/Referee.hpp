//
//  Referee.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/22/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#ifndef Referee_hpp
#define Referee_hpp

#include "Gem.hpp"

class Referee: public Gem{
    
    
public:
    void load(Output* output, int w, int h=0);
    char* getType();
private:
    
};


#endif /* Referee_hpp */
