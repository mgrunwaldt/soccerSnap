//
//  Constants.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/26/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#ifndef Constants_hpp
#define Constants_hpp

static class Constants{
public:
    constexpr static const float FPS = 60;
    constexpr static const float FRAME_DELAY = 1000/FPS;
    
    constexpr static const float LOADER_ANIMATION_SECONDS = 2.5;
    constexpr static const float LOADER_WAITING_SECONDS = 2;
    constexpr static const float LOGO_BALL_X_PROPORTION = 59.0/67.0;
    constexpr static const float BALL_LOGO_Y_PROPORTION = 7.0/32.0;
    
    constexpr static const int GAME_SCREEN_WIDTH = 1072;
    constexpr static const int GAME_SCREEN_HEIGHT = 720;
    constexpr static const int FIELD_WIDTH = 545;
    constexpr static const int FIELD_LINE_WIDTH = 13;
    
    constexpr static const int GEMS_PER_ROW = 8;
    constexpr static const int TARGET_POINTS = 1500;
    constexpr static const int MATCH_TIME = 120;
    
    constexpr static const float GEM_VELOCITY = 3.7;
};
#endif /* Constants_hpp */
