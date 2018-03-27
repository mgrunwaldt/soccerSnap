//
//  Ball.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/22/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Ball.hpp"

void Ball::load(Output*output, int w, int h){
    spriteName = "Ball";
    Gem::load(output, w);
}
