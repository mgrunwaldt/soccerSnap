//
//  Output.cpp
//  SDL_Window_Test
//
//  Created by Matias Grunwaldt on 3/20/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Output.hpp"

Output::~Output(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    loadedTextures.clear();
    window = NULL;
    renderer = NULL;
    SDL_Quit();
    IMG_Quit();
}

bool Output::init(){
    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, SDL_WINDOW_SHOWN);
        if(window){
            renderer = SDL_CreateRenderer(window, -1, 0);
            if(renderer){
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderClear(renderer);
                return true;
            }
        }
    }
    return false;
}

void Output::clearScreen(){
    SDL_RenderClear(renderer);
}

void Output::drawScreen(){
    SDL_RenderPresent(renderer);
   
}
void Output::loadTexture(char* name){
    SDL_Texture* texture;
    
    std::string folder = "assets/";
    std::string extension = ".png";
    std::string location = folder+name+extension;
    char* spriteName = strdup(location.c_str());
    SDL_Surface* pTempSurface = IMG_Load(spriteName);
    free(spriteName);
    if( pTempSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n",name, IMG_GetError() );
    }
    texture = SDL_CreateTextureFromSurface(renderer, pTempSurface);
    
    
    SDL_FreeSurface(pTempSurface);
    loadedTextures[name] = texture;
}

SDL_Texture* Output::getTexture(char* name){
    SDL_Texture* texture = loadedTextures[name];
    if(texture == nullptr){
        loadTexture(name);
        texture = loadedTextures[name];
    }
    return texture;
}

void Output::addSprite(char* name,int x, int y, int width, int height){
    SDL_Texture * texture = getTexture(name);
    SDL_Rect destRect;

    destRect.x = x;
    destRect.y = y;
    
    destRect.w = width;
    if(height == 0){
        int originalWidth = 0;
        int originalHeight = 0;
        SDL_QueryTexture(texture, NULL, NULL, &originalWidth, &originalHeight);
        height = (width*originalHeight / originalWidth);
    }
    destRect.h = height;
    SDL_RenderCopy(renderer, texture, NULL, &destRect);

}
