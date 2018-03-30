//
//  Output.cpp
//  SDL_Window_Test
//
//  Created by Matias Grunwaldt on 3/20/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Output.hpp"

#pragma mark Setup


void Output::init(){
    OutputInitException ex;
    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Constants::GAME_SCREEN_WIDTH, Constants::GAME_SCREEN_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
        if(window){
            renderer = SDL_CreateRenderer(window, -1, 0);
            if(renderer){
                SDL_SetRenderDrawColor(renderer, 0, 103, 20, 255);
                SDL_RenderClear(renderer);
                setRes();
                return;
            } else
                ex.setMessage("Couldn't create Renderer");
        }
        else
            ex.setMessage("Couldn't create Window");
    }
    else
        ex.setMessage(SDL_GetError());
    throw ex;
}



#pragma mark Screen

void Output::clearScreen(){
    SDL_RenderClear(renderer);
}

void Output::drawScreen(){
    SDL_RenderPresent(renderer);
}

bool Output::screenIsHd(){
    int w1, w2, h1, h2;
    SDL_GL_GetDrawableSize(window, &w1, &h1);
    SDL_GetWindowSize(window, &w2, &h2);
    if(w1>w2){
        return true;
    }
    return false;;
}

void Output::setRes(){
    if(screenIsHd()){
        winRes = HIGH;
    }
    else winRes = SD;
}

#pragma mark Images
void Output::loadTexture(string name){
    SDL_Texture* texture;
    
    string folder = "assets/";
    string extension = ".png";
    string location = folder+name+extension;
    char* spriteName = strdup(location.c_str());
    SDL_Surface* pTempSurface = IMG_Load(spriteName);
    free(spriteName);
    if( pTempSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n",name.c_str(), IMG_GetError() );
    }
    texture = SDL_CreateTextureFromSurface(renderer, pTempSurface);
    
    
    SDL_FreeSurface(pTempSurface);
    loadedTextures[name] = texture;
}

SDL_Texture* Output::getTexture(string name){
    SDL_Texture* texture = loadedTextures[name];
    if(texture == nullptr){
        loadTexture(name);
        texture = loadedTextures[name];
    }
    return texture;
}



void Output::addSprite(string name,int x, int y, int width, int height, int angle, int alpha){
    SDL_Texture * texture = getTexture(name);
    SDL_Rect destRect;
   
    setRes();
    
    destRect.x = x*winRes;
    destRect.y = y*winRes;
    
    destRect.w = width*winRes;
    
    if(height == 0){
        int originalWidth = 0;
        int originalHeight = 0;
        SDL_QueryTexture(texture, NULL, NULL, &originalWidth, &originalHeight);
        height = (width*originalHeight / originalWidth);
    }
    destRect.h = height*winRes;
    if(alpha != 255){
        SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND );
        SDL_SetTextureAlphaMod(texture, alpha );
    }
    SDL_RenderCopyEx(renderer, texture, NULL, &destRect, angle, NULL, SDL_FLIP_NONE);

}

Point Output::getSpriteDimensions(string name){
    SDL_Texture * texture = getTexture(name);
    int originalWidth = 0;
    int originalHeight = 0;
    SDL_QueryTexture(texture, NULL, NULL, &originalWidth, &originalHeight);
    Point toReturn;
    toReturn.x = originalWidth/winRes;
    toReturn.y = originalHeight/winRes;
    return toReturn;
}

#pragma mark Destructor:

Output::~Output(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    for(map<string, SDL_Texture*>::iterator itr = loadedTextures.begin(); itr != loadedTextures.end(); itr++)
    {
        SDL_DestroyTexture(itr->second);
    }
    loadedTextures.clear();
    SDL_Quit();
    IMG_Quit();
}
