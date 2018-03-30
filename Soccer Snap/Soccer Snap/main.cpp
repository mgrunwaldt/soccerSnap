//
//  main.cpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/21/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#include <iostream>
#include "WindowManager.hpp"

WindowManager * manager = nullptr;
int main(int argc, const char * argv[]) {
    manager = new WindowManager();
    manager->showLoader();
}
