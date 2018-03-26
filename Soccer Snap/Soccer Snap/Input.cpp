//
//  Input.cpp
//  SDL_Window_Test
//
//  Created by Matias Grunwaldt on 3/20/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Input.hpp"
/*
 while( SDL_PollEvent( &e ) != 0 )
 {
 */

bool Input::eventsLeft(){
    if(SDL_PollEvent(NULL) != 0){
        return true;
    }
    return false;
}
EventType Input::checkEvent(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            return EventType::Exit;
            break;
        case SDL_MOUSEBUTTONDOWN:
            return EventType::MouseDown;
        case SDL_MOUSEBUTTONUP:
            return EventType::MouseUp;
        case SDL_MOUSEMOTION:
            return EventType::MouseMotion;
        default:
            return EventType::Unknown;
            break;
    }
}

Point Input::getMousePosition(){
    int x, y;
    SDL_GetMouseState(&x, &y);
    return Point(x, y);
}
