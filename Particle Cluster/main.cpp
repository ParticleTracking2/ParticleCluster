//
//  main.cpp
//  Particle Cluster
//
//  Created by Juan Sebastian Silva Leal on 10/6/15.
//  Copyright © 2015 Juan Silva. All rights reserved.
//

#include <iostream>
#include <vector>
#include "ParticleData.hpp"

int main(int argc, const char * argv[]) {
    
    using namespace std;
    // insert code here...
    cout << "Hello, World!\n";
    
    ParticleData* pdata = new ParticleData(10, 10.1f);
    cout << "pdata x: " << +pdata->GetPosition().x << "\n";
    cout << "pdata y: " << +pdata->GetPosition().y << "\n";
    delete pdata;
    
    return 0;
}
