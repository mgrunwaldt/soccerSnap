//
//  Tools.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/21/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#ifndef Tools_hpp
#define Tools_hpp

#include "SDL2/SDL.h"
class Tools{
public:
    static Uint32 getTicks(){
        return SDL_GetTicks();
    };
    static void delay(Uint32 ms){
        SDL_Delay(ms);
    };

};
#endif /* Tools_hpp */
