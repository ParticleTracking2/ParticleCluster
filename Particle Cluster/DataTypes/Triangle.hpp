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
#include "Vector2.hpp"

class Triangle
{
private:
    Vector2 position1;
    Vector2 position2;
    Vector2 position3;
    
public:
    Triangle();
    Triangle(Vector2 pos1, Vector2 pos2, Vector2 pos3);
    virtual ~Triangle();
    Vector2 GetPosition1();
    Vector2 GetPosition2();
    Vector2 GetPosition3();
};

#endif /* Triangle_hpp */
