//
//  ParticleData.cpp
//  Particle Cluster
//
//  Created by Juan Sebastian Silva Leal on 10/6/15.
//  Copyright © 2015 Juan Silva. All rights reserved.
//

#include "ParticleData.hpp"

ParticleData::ParticleData()
{
    position.x = 0;
    position.y = 0;
    q4Value = 0;
}

ParticleData::ParticleData(Point2D pos)
{
    position.x = pos.x;
    position.y = pos.y;
    q4Value = 0;
}

ParticleData::ParticleData(float x, float y)
{
    position.x = x;
    position.y = y;
    q4Value = 0;
}

ParticleData::ParticleData(Point2D pos, float q4)
{
    position.x = pos.x;
    position.y = pos.y;
    q4Value = q4;
}

ParticleData::ParticleData(float x, float y, float q4)
{
    position.x = x;
    position.y = y;
    q4Value = q4;
}

ParticleData::~ParticleData()
{
    position.x = 0;
    position.y = 0;
    q4Value = 0;
}

Point2D ParticleData::GetPosition()
{
    return position;
}

float ParticleData::GetQ4()
{
    return q4Value;
}
