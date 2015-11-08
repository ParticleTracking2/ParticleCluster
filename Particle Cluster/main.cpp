//
//  main.cpp
//  Particle Cluster
//
//  Created by Juan Sebastian Silva Leal on 10/6/15.
//  Copyright © 2015 Juan Silva. All rights reserved.
//

#include <iostream>
#include <vector>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
typedef CGAL::Delaunay_triangulation_2<Kernel> Delaunay;
typedef Kernel::Point_2 Point;

void load_points(std::vector< Point >& points)
{
    points.push_back(Point(1., 1.));
    points.push_back(Point(2., 1.));
    points.push_back(Point(2., 2.));
    points.push_back(Point(1., 2.));
}

int main(int argc, const char * argv[]) {
    
    using namespace std;
    // insert code here...
    cout << "Hello, World!\n";

    // -----
    std::vector< Point > points;
    load_points(points);
    Delaunay triangulation;
    triangulation.insert(points.begin(), points.end());
    std::cout << "Vertices: " << triangulation.number_of_vertices() << std::endl;
    std::cout << "Faces: " << triangulation.number_of_faces() << std::endl;
    
    Delaunay::Finite_faces_iterator fit;
    int n_triangles = 0;
    for (fit = triangulation.finite_faces_begin(); fit != triangulation.finite_faces_end(); fit++){
        Delaunay::Face_handle face = fit;
        std::cout << "Triangle:\t" << triangulation.triangle(face) << std::endl;
        std::cout << "Vertex 0:\t" << triangulation.triangle(face)[0] << std::endl;
        std::cout << "Vertex 0:\t" << triangulation.triangle(face)[1] << std::endl;
        std::cout << "Vertex 0:\t" << triangulation.triangle(face)[2] << std::endl;
        ++n_triangles;
    }
    
    std::cout << "Triangles: " << n_triangles << std::endl;
    
    return 0;
}


