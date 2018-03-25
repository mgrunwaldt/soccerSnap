//
//  Point.hpp
//  Soccer Snap
//
//  Created by Matias Grunwaldt on 3/24/18.
//  Copyright © 2018 grunwaldt. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

class Point
{
public:
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
    int x, y;

};
#endif /* Point_hpp */
