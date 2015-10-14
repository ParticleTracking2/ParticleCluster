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
#include "Vector2.hpp"

class ParticleData
{
private:
    Vector2 position;
    float q4Value;
    
public:
    ParticleData();
    ParticleData(float x, float y);
    ParticleData(Vector2 pos);
    ParticleData(float x, float y, float q4);
    ParticleData(Vector2 pos, float q4);
    virtual ~ParticleData();
    Vector2 GetPosition();
    float GetQ4();
};

#endif /* ParticleData_hpp */
