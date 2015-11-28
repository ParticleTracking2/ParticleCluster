//
//  VoronoiWrapper.cpp
//  Particle Cluster
//
//  Created by Juan Sebastian Silva Leal on 11/27/15.
//  Copyright © 2015 Juan Silva. All rights reserved.
//

#include "VoronoiWrapper.hpp"

void VoronoiDiagram::GetDiagram(vector<Point2D>& points)
{
    VD voronoiDiagram;

    // Add and Convert
    unsigned long vectorSize = points.size();
    for(unsigned long i=0; i<vectorSize; ++i){
        voronoiDiagram.insert(Site_2(points[i].x, points[i].y));
    }
    std::cout << "Voronoi Diagram" << std::endl;
    
    // Verify
    if(!voronoiDiagram.is_valid()){
        std::cerr << "Invalid Diagram" << std::endl;
        return;
    }
    
    // Get Vertices
    VD::Vertex_iterator vit;
    for(vit = voronoiDiagram.vertices_begin(); vit != voronoiDiagram.vertices_end(); vit++){
        VD::Vertex_handle vertex = vit;
        std::cout << "Vertex: " << vertex->point() << std::endl;
    }
    
    // Get Faces/Cells
    VD::Face_iterator fit;
    for(fit = voronoiDiagram.faces_begin(); fit != voronoiDiagram.faces_end(); fit++){
        VD::Face_handle face = fit;
        std::cout << "Cells: " << std::endl;
        Ccb_halfedge_circulator ec_start = face->ccb();
        Ccb_halfedge_circulator ec = ec_start;
        do {
            if(ec->has_target()){
                std::cout << ec->target()->point() << " ; ";
            }else{
                std::cout << "INFPoint" << " ; ";
            }
            
        }while(++ec != ec_start);
        std::cout << std::endl;
    }
}