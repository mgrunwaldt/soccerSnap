//
//  GameObject.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/21/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//
#ifndef GameObject_hpp
#define GameObject_hpp


class GameObject
{
public:
    virtual void render() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
    
protected:
    virtual ~GameObject(){};
    
};

#endif /* GameObject_hpp */
