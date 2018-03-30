//
//  Output.hpp
//  SDL_Window_Test
//
//  Created by Matias Grunwaldt on 3/20/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#ifndef Output_hpp
#define Output_hpp

#include "SDL2/SDL.h"
#include <SDL2_image/SDL_image.h>
#include <string>
#include <vector>
#include <map>
#include "Point.hpp"
#include "Constants.hpp"
#include "OutputInitException.hpp"

using namespace std;

class Output{
public:
    ~Output();
    
    void init();
    void clearScreen();
    void drawScreen();
    
    void addSprite(string name,int x, int y, int width, int height=0, int angle = 0, int alpha = 255);
    
    Point getSpriteDimensions (string name);
    
    void setRes();
private:
    enum resolutions{
        SD = 1,
        HIGH = 2
    };
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool screenIsHd();
    int winRes;
    void loadTexture(string name);
    SDL_Texture* getTexture(string name);
    map<string, SDL_Texture*> loadedTextures;
    
};

#endif /* Output_hpp */
