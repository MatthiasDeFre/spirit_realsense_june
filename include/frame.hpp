#pragma once
#include <vector>
#include "point_cloud_data.h"
class PointCloud;
struct Point {
    float x, y, z;
    uint8_t r, g, b;
};

class Frame {
    public:
        Frame(unsigned int frame_nr) : frame_nr(frame_nr) {};
        virtual ~Frame() = default;
        virtual unsigned int get_frame_size() = 0;
        virtual Vertex* get_vertex_array() = 0;
        virtual Color* get_color_array() = 0;

        unsigned int get_frame_nr() {return frame_nr;};
    protected:
        unsigned int frame_nr;
};