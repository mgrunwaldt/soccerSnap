//
//  Input.cpp
//  SDL_Window_Test
//
//  Created by Matias Grunwaldt on 3/20/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Input.hpp"

EventType Input::checkEvent(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            return EventType::Exit;
            break;
        default:
            return EventType::Unknown;
            break;
    }
}
