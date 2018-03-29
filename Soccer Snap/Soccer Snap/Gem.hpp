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
#include <string>

class Gem: public GameObject{

    
public:
    void render();
    void update();
    void clean();
    void setPos(int gridX, int gridY);
    virtual void load(Output* output, int w, int h=0);
    virtual char* getType()=0;
    void setSprite(char* spriteName);
    bool isSelected();
    void setSelected(bool isSelected);
    
    void setInitialAnimationPosition();
    void switchWithGem (int gridX,int gridY);
    bool isInPlace();
    bool isSwitching();
    bool isGoingDown();
    bool hasMouseInside (Point mousePosition);
    
    int boardX;
    int boardY;
    
    void setDeleted();
    bool needsDelete();
    void setNextPos(int gridY);
    
    ~Gem();
private:
    Output* outputFacade;
    float x;
    float y;
    float finalX;
    float finalY;
    float xVector;
    float yVector;
    
    int width;
    int height;
    bool selected;
    int initialXPosition;
    int initialYPosition;
    int firstStopX;
    int firstStopY;
    bool goingToFirstStop;
    bool goingToPosition;
    bool inPlace;
    bool switching;
    bool willBeDeleted;
    bool goingDown;
    
    
    
protected:
    char* spriteName;
    
};
#endif /* Gem_hpp */
