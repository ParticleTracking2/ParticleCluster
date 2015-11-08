#!/bin/sh
cgal_create_CMakeLists -s main
cmake -DCGAL_DIR=/usr/local/Cellar/cgal/4.6.3 .
make
