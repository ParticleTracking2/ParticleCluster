//
//  main.cpp
//  Particle Cluster
//
//  Created by Juan Sebastian Silva Leal on 10/6/15.
//  Copyright © 2015 Juan Silva. All rights reserved.
//

#include <iostream>
#include <vector>
#include "DelaunayWrapper.hpp"
#include "VoronoiWrapper.hpp"
#include "Point2D.hpp"
#include "Triangle.hpp"

void load_points(std::vector< Point2D >& points)
{
    points.push_back(Point2D(0.5, 0));
    points.push_back(Point2D(0, 0.5));
    points.push_back(Point2D(-0.5, -0.5));
    points.push_back(Point2D(-0.2, -0.1));
    points.push_back(Point2D(-0.1, 0.1));
    points.push_back(Point2D(0.1, -0.1));
    points.push_back(Point2D(0.1, 0.1));
}

int main(int argc, const char * argv[]) {
    
    using namespace std;
    cout << "Hello, World!\n";

    // -----
    vector< Point2D > points;
    vector< Triangle* > triangles;
    load_points(points);
    DelaunayTriangulation triangulation;
    triangles = triangulation.GetTriangulation(points);
    std::cout << "Triangles: " << triangles.size() << std::endl;
    
    for (unsigned long i = 0; i<triangles.size(); ++i){
        std::cout << "Triangle:\t" << i << std::endl;
        std::cout << "Vertex 0:\t" << triangles[i]->GetPosition1().x << ";" << triangles[i]->GetPosition1().y << std::endl;
        std::cout << "Vertex 1:\t" << triangles[i]->GetPosition2().x << ";" << triangles[i]->GetPosition2().y << std::endl;
        std::cout << "Vertex 2:\t" << triangles[i]->GetPosition3().x << ";" << triangles[i]->GetPosition3().y << std::endl;
    }
    
    VoronoiDiagram diagram;
    diagram.GetDiagram(points);
    
    return 0;
}


