//
//  Triangle.hpp
//  Particle Cluster
//
//  Created by Juan Sebastian Silva Leal on 10/13/15.
//  Copyright © 2015 Juan Silva. All rights reserved.
//

#ifndef Triangle_hpp
#define Triangle_hpp

#include <stdio.h>
#include "Point2D.hpp"

class Triangle
{
private:
    Point2D position1;
    Point2D position2;
    Point2D position3;
    
public:
    Triangle();
    Triangle(Point2D pos1, Point2D pos2, Point2D pos3);
    virtual ~Triangle();
    Point2D GetPosition1();
    void SetPosition1(Point2D pos1);
    Point2D GetPosition2();
    void SetPosition2(Point2D pos2);
    Point2D GetPosition3();
    void SetPosition3(Point2D pos3);
};

#endif /* Triangle_hpp */
