//
//  MainMenu.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/25/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#ifndef MainMenu_hpp
#define MainMenu_hpp

#include "Output.hpp"
#include "Input.hpp"
#include "Scene.hpp"
#include "Button.hpp"
#include <string>
#include <vector>


class MainMenu:public Scene{
public:
    MainMenu(Output* o, Input* i);
    ~MainMenu();
    
    void load();
    void handleEvent(EventType e);
    void update();
    void render();
    
    bool isActive();
    int getChosenCountry();
    
    
private:
    Output * output;
    Input * input;
    bool active;
    string countries[5] = {"Uruguay","Portugal","England","Brazil","Russia"};
    int selectedCountry;
    
    float ballX,ballY,logoX,logoY;
    Point ballDimensions, logoDimensions, pickTeamDimensions, separatorDimensions;
    
    Button* playButton;
    Button* countryButtons[5];
    
    void loadPlayButton();
    void loadCountries();
    void loadPositions();
    void renderCountryButtons();
    void renderStaticImages();
    
};
#endif /* MainMenu_hpp */
