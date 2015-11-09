//
//  ParticleData.hpp
//  Particle Cluster
//
//  Created by Juan Sebastian Silva Leal on 10/6/15.
//  Copyright © 2015 Juan Silva. All rights reserved.
//

#ifndef ParticleData_hpp
#define ParticleData_hpp

#include <stdio.h>
#include "Point2D.hpp"

class ParticleData
{
private:
    Point2D position;
    float q4Value;
    
public:
    ParticleData();
    ParticleData(float x, float y);
    ParticleData(Point2D pos);
    ParticleData(float x, float y, float q4);
    ParticleData(Point2D pos, float q4);
    virtual ~ParticleData();
    Point2D GetPosition();
    float GetQ4();
};

#endif /* ParticleData_hpp */
