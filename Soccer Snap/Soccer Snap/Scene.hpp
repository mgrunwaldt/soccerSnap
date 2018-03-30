//
//  Scene.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/25/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

class Scene
{
public:
    virtual void load() = 0;
    virtual void handleEvent(EventType e) = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    
    virtual bool isActive() = 0;

    
};
#endif /* Scene_hpp */
