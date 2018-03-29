//
//  Player.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/22/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Player.hpp"
void Player::load(Output*output, int w, int h){
    Gem::load(output, w);
}

char* Player::getType(){
    return "Player";
}
