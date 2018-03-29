//
//  Referee.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/22/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include "Referee.hpp"

void Referee::load(Output*output, int w, int h){
    spriteName = "Referee";
    Gem::load(output, w);
}

char* Referee::getType(){
    return "Referee";
}
