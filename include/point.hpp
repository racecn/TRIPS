#pragma once
#include <glm/glm.hpp>  // Assuming you're using GLM for vector math

// Define a struct to represent a point in the E57 file
struct Point {
    glm::vec3 position;  // 3D position (x, y, z)
    glm::vec3 color;     // RGB color
    double size;         // Size of the point (can be used for rendering)
};
