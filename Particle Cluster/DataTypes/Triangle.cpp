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

Triangle::Triangle(Point2D pos1, Point2D pos2, Point2D pos3)
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

Point2D Triangle::GetPosition1()
{
    return position1;
}

void Triangle::SetPosition1(Point2D pos1)
{
    position1 = pos1;
}

Point2D Triangle::GetPosition2()
{
    return position2;
}

void Triangle::SetPosition2(Point2D pos2)
{
    position2 = pos2;
}

Point2D Triangle::GetPosition3()
{
    return position3;
}

void Triangle::SetPosition3(Point2D pos3)
{
    position3 = pos3;
}

