//
//  DelaunayWrapper.cpp
//  Particle Cluster
//
//  Created by Juan Sebastian Silva Leal on 11/8/15.
//  Copyright © 2015 Juan Silva. All rights reserved.
//

#include "DelaunayWrapper.hpp"

vector<Triangle*> DelaunayTriangulation::GetTriangulation(vector<Point2D>& points)
{
    // Convert
    vector<CGALPoint> cgalPoints;
    unsigned long vectorSize = points.size();
    for(unsigned long i=0; i<vectorSize; ++i){
        cgalPoints.push_back(CGALPoint(points[i].x, points[i].y));
    }
    // Add Points
    CGALDelaunay triangulation;
    triangulation.insert(cgalPoints.begin(), cgalPoints.end());
    
    // Get Triangles
    vector<Triangle*> result;
    CGALDelaunay::Finite_faces_iterator fit;
    for (fit = triangulation.finite_faces_begin(); fit != triangulation.finite_faces_end(); fit++){
        CGALDelaunay::Face_handle face = fit;
        Triangle* tri = new Triangle();
        tri->SetPosition1(Point2D(triangulation.triangle(face)[0].x(), triangulation.triangle(face)[0].y()));
        tri->SetPosition2(Point2D(triangulation.triangle(face)[1].x(), triangulation.triangle(face)[1].y()));
        tri->SetPosition3(Point2D(triangulation.triangle(face)[2].x(), triangulation.triangle(face)[2].y()));
        result.push_back(tri);
    }
    
    return result;
}
