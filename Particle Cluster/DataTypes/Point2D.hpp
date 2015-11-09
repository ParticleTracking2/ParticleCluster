//
//  Point2D.hpp
//  Particle Cluster
//
//  Created by Juan Sebastian Silva Leal on 10/13/15.
//  Copyright © 2015 Juan Silva. All rights reserved.
//

#ifndef Point2D_hpp
#define Point2D_hpp

#include <stdio.h>

struct Point2D
{
    float x;
    float y;
    
    Point2D()
    {
        x = 0;
        y = 0;
    }
    
    Point2D(float givenX, float givenY)
    {
        x = givenX;
        y = givenY;
    }
};


#endif /* Point2D_hpp */
