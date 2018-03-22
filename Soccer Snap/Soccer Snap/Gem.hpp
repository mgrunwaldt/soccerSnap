//
//  Gem.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/21/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#ifndef Gem_hpp
#define Gem_hpp

#include "GameObject.hpp"
#include "Output.hpp"

class Gem: public GameObject{

    
public:
    virtual void draw();
    virtual void update();
    virtual void clean();
    void load(Output* output,char* sprite, int w, int h=0);
    ~Gem();
private:
    char* spriteName;
    Output* outputFacade;
    int x;
    int y;
    int width;
    int height;
};
#endif /* Gem_hpp */
