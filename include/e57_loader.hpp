#pragma once

#include <vector>
#include <string>
#include <glm/glm.hpp>
#include <E57Format.h>

// Define a struct to represent a point in the E57 file
struct Point {
    glm::vec3 position;  // 3D position (x, y, z)
    glm::vec3 color;     // RGB color
    double size;         // Size of the point (can be used for rendering)

    // Constructor for convenience
    Point(const glm::vec3& pos = glm::vec3(0.0f), 
          const glm::vec3& col = glm::vec3(1.0f), 
          double sz = 1.0) 
        : position(pos), color(col), size(sz) {}
};

class E57Loader {
public:
    static std::vector<Point> load_e57_file(const std::string& filename);

private:
    static constexpr size_t CHUNK_SIZE = 1024;
    static bool check_required_fields(const e57::StructureNode& prototype);
};