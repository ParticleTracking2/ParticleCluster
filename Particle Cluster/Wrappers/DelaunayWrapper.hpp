//
//  DelaunayWrapper.hpp
//  Particle Cluster
//
//  Created by Juan Sebastian Silva Leal on 11/8/15.
//  Copyright © 2015 Juan Silva. All rights reserved.
//

#ifndef DelaunayWrapper_hpp
#define DelaunayWrapper_hpp

#include <stdio.h>
#include <vector>
#include "Triangle.hpp"
#include "Point2D.hpp"
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel CGALKernel;
typedef CGAL::Delaunay_triangulation_2<CGALKernel> CGALDelaunay;
typedef CGALKernel::Point_2 CGALPoint;
using namespace std;

class DelaunayTriangulation
{
public:
  static vector<Triangle*> GetTriangulation(vector<Point2D>& points);
};

#endif /* DelaunayWrapper_hpp */
