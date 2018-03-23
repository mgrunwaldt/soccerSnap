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
    void draw();
    void update();
    void clean();
    void setPos(int gridX, int gridY);
    virtual void load(Output* output, int w, int h=0);
    void setSprite(char* spriteName);
    
    ~Gem();
private:
    Output* outputFacade;
    int x;
    int y;
    int width;
    int height;
protected:
    char* spriteName;
};
#endif /* Gem_hpp */
