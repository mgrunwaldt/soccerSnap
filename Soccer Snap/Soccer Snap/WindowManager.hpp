//
//  WindowManager.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/25/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#ifndef WindowManager_hpp
#define WindowManager_hpp

#include "Output.hpp"
#include "Input.hpp"
#include "Loader.hpp"
#include "Tools.hpp"
#include "Scene.hpp"
#include "MainMenu.hpp"
#include "GameScene.hpp"
#include "Constants.hpp"
#include "OutputInitException.hpp" 

#include <chrono>
#include <thread>
#include <ostream>

using namespace std;


class WindowManager{
public:
    WindowManager();
    ~WindowManager();
    
    void showLoader();
    void showMainMenu();
    void showGameScreen(int selectedCountry);
    
    void presentScene();
    
private:
    Output *output;
    Input * input;
    
    Scene * activeScene;
    Loader * loaderScene;
    MainMenu * mainMenuScene;
    GameScene* gameScene;
    
    bool gameRunning;
    Uint32 frameStart;
    float frameTime;

};
#endif /* WindowManager_hpp */
