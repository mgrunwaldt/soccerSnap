//
//  Input.hpp
//  SDL_Window_Test
//
//  Created by Matias Grunwaldt on 3/20/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#ifndef Input_hpp
#define Input_hpp

#include "SDL2/SDL.h"
#include "EventType.hpp"
#include "Point.hpp"
class Input{
public:
    EventType checkEvent();
    Point getMousePosition();
    bool eventsLeft();

    
private:
    
};
#endif /* Input_hpp */
