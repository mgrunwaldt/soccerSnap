//
//  OutputInitException.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/29/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#ifndef OutputInitException_hpp
#define OutputInitException_hpp

using namespace std;
#include <exception>
#include <iostream>

class OutputInitException : public exception
{
    string message;
public:
    const char * what ()
    {
        return "Output couldn't initialize";
    }
    
    string getMessage(){
       return message;
    }
    
    void setMessage (string m){
        message = m;
    }
};

#endif /* OutputInitException_hpp */
