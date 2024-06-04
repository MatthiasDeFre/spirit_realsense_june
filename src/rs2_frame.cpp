#include "rs2_frame.hpp"
#include <algorithm>

void RS2Frame::make_color_array(unsigned int width, unsigned height, unsigned int bpp, unsigned int sib, const uint8_t *texture)
{
    if(colors != nullptr) {
        delete colors;
    }
    colors = new Color[points.size()];
    for(unsigned int i = 0; i < points.size(); i++) {
        auto tex_coords = points.get_texture_coordinates();
        float u = tex_coords[i].u;
        float v = tex_coords[i].v;
        
        int texture_x = std::min(std::max(unsigned int(u * width + .5f), unsigned int (0)), width - 1);
        int texture_y = std::min(std::max(unsigned int(v * height + .5f), unsigned int (0)), height - 1);

        int bytes = texture_x * bpp;   // Get # of bytes per pixel
        int strides = texture_y * sib; // Get line width in bytes
        int tex_index = (bytes + strides);
        colors[i] = {
            texture[tex_index],
            texture[tex_index+1],
            texture[tex_index+2],
        };
    }
    
}


