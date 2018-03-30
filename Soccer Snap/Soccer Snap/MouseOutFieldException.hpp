//
//  MouseOutFieldException.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/30/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#ifndef MouseOutFieldException_hpp
#define MouseOutFieldException_hpp

using namespace std;
#include <exception>
#include <iostream>

class MouseOutFieldException : public exception
{
    string message;
public:
    const char * what ()
    {
        return "Mouse is outside";
    }
};
#endif /* MouseOutFieldException_hpp */
