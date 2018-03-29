//
//  Goalkeeper.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/22/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#ifndef Goalkeeper_hpp
#define Goalkeeper_hpp

#include "Gem.hpp"

class Goalkeeper: public Gem{
    
    
public:
    void load(Output* output, int w, int h=0);
    char* getType();
private:
    
};


#endif /* Goalkeeper_hpp */
