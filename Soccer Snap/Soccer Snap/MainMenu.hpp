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

class MainMenu:public Scene{
public:
    MainMenu(Output* o, Input* i);
    ~MainMenu();
    
    
    void load();
    void handleEvents();
    void update();
    void render();
    void clean();
    
    bool isActive();
    
    
    
private:
    Output *output;
    Input * input;
    bool active;
    char* countries[5];
    int selectedCountry;
    char* logo;
    char* logoBall;
    
    Button* playButton;
    Button* countryButtons[5];
    
    void loadPlayButton();
    void loadCountries();
    
};
#endif /* MainMenu_hpp */
