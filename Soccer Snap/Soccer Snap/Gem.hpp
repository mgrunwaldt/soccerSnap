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
    ~Gem();
    Gem(string name);
    
    void render();
    void update();
    void load(Output* output);
    
    void setPos(int gridX, int gridY);
    void setInitialAnimationPosition();
    void setNewDirection(int gridX, int gridY);
    void switchWithGem (int gridX,int gridY);

    void setSelected(bool isSelected);
    bool isSelected();
    bool isMoving();
    void setMoving(bool move);
    
    bool hasMouseInside (Point mousePosition);
    
    void setDeleted();
    bool needsDelete();
    void setNextPos(int gridY);
    
    string getType();
    
    int boardX;
    int boardY;
    
    int getValue(int sequenceNumber);
    void setOpponent();
    bool isOpponent();
    
private:
    Output* outputFacade;
    float x;
    float y;
    float finalX;
    float finalY;
    float xVector;
    float yVector;
    
    int width;
    bool selected;
    bool moving;
    bool willBeDeleted;
    bool goingToFirstStop;
    bool opponent;
    
    
   
    
    
    
protected:
    string spriteName;
    
};
#endif /* Gem_hpp */
