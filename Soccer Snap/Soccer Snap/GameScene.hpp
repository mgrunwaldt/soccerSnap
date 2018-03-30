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

using namespace std;


class GameScene:public Scene{
public:
    GameScene(Output* o, Input* i);
    ~GameScene();
    
    
    void load();
    void handleEvent(EventType e);
    void update();
    void render();
    
    void setCountries(int countryPos);
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
    string countries[5]= {"Uruguay","Portugal","England","Brazil","Russia"};
    string selectedCountry;
    string opponentCountry;
    
    Button* homeButton;
    Button* pauseButton;
    
    Timer* gameTimer;
    Field* field;
    
    void loadGUIElements();
    void loadTimer();
    void loadField();
    void renderImages();
    void renderPoints();
    
    void goToMainMenu();
    
};

#endif /* GameScene_hpp */
