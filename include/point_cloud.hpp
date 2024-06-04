#pragma once
#include <cstdint>
#include "frame.hpp"
#include "point_cloud_data.h"
struct PointCloud {
    unsigned int n_points;
    Vertex* coords;
    Color* colors;
    Frame* frame_pointer = nullptr; // DO NOT USE OR FREE YOURSELF!

    ~PointCloud() {
        delete frame_pointer;
    };
};