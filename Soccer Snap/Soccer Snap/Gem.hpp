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
    void render();
    void update();
    void clean();
    void setPos(int gridX, int gridY);
    virtual void load(Output* output, int w, int h=0);
    void setSprite(char* spriteName);
    bool isSelected();
    void setInitialAnimationPosition();
    
    ~Gem();
private:
    Output* outputFacade;
    float x;
    float y;
    float finalX;
    float finalY;
    float xVector;
    float yVector;
    int boardX;
    int boardY;
    int width;
    int height;
    bool selected;
    int initialXPosition;
    int initialYPosition;
    int firstStopX;
    int firstStopY;
    bool goingToFirstStop;
    bool goingToPosition;
protected:
    char* spriteName;
};
#endif /* Gem_hpp */
