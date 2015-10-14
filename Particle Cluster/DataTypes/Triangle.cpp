//
//  Triangle.cpp
//  Particle Cluster
//
//  Created by Juan Sebastian Silva Leal on 10/13/15.
//  Copyright © 2015 Juan Silva. All rights reserved.
//

#include "Triangle.hpp"

Triangle::Triangle()
{
    position1.x = 0;
    position1.y = 0;
    position2.x = 0;
    position2.y = 0;
    position3.x = 0;
    position3.y = 0;
}

Triangle::Triangle(Vector2 pos1, Vector2 pos2, Vector2 pos3)
{
    position1 = pos1;
    position2 = pos2;
    position3 = pos3;
}

Triangle::~Triangle()
{
    position1.x = 0;
    position1.y = 0;
    position2.x = 0;
    position2.y = 0;
    position3.x = 0;
    position3.y = 0;
}

Vector2 Triangle::GetPosition1()
{
    return position1;
}

Vector2 Triangle::GetPosition2()
{
    return position2;
}

Vector2 Triangle::GetPosition3()
{
    return position3;
}
