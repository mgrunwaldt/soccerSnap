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

#include "GameState.hpp"
#include "GameLoading.hpp"
#include "GamePlaying.hpp"
#include "GamePaused.hpp"
#include "GameFinished.hpp"

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
    void addTime (int timeToAdd);
    
    void updateField();
    void handleFieldEvent(EventType e);
    bool fieldLoaded();
    void updateTimer();
    void skipLoader();
    
    void showPlayButton();
    void showPauseButton();
    
    bool hasFinished();
    bool hasWon();
    void hideEndAnimation();
    
    Button* pauseButton;
    Button* playButton;
    
    Output *output;
    Input * input;

private:
    
    int points;
    int opponentPoints;
    bool active;
    
    string countries[5]= {"Uruguay","Portugal","England","Brazil","Russia"};
    string selectedCountry;
    string opponentCountry;
    
    Button* homeButton;
    
    Timer* gameTimer;
    Field* field;
    
    void loadGUIElements();
    void loadTimer();
    void loadField();
    void renderImages();
    void renderPoints();
        
    GameState* state;
    
};

#endif /* GameScene_hpp */
