//
//  GameScene.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/26/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include "Output.hpp"
#include "Input.hpp"
#include "Scene.hpp"
#include "Button.hpp"
#include "Timer.hpp"
#include "Field.hpp"
#include <string>
#include <vector>


class GameScene:public Scene{
public:
    GameScene(Output* o, Input* i);
    ~GameScene();
    
    
    void load();
    void handleEvents();
    void update();
    void render();
    void clean();
    
    void setCountries(int countryPos);
    void setDuration(int time);
    bool isActive();
    
    void addPoints(int pointsToAdd);
    void addOpponentPoints(int pointsToAdd);
    
private:
    Output *output;
    Input * input;
    int duration;
    int points;
    int opponentPoints;
    bool active;
    char* countries[5]= {"Uruguay","Portugal","England","Brazil","Russia"};
    char* selectedCountry;
    char* opponentCountry;
    char* logo;
    char* logoBall;
    
    Button* homeButton;
    Button* pauseButton;
    Button* countryButtons[5];
    
    Timer* gameTimer;
    Field* field;
    
    void loadGUIElements();
    void loadTimer();
    void loadField();
    void renderImages();
    void renderPoints();
    
};

#endif /* GameScene_hpp */
