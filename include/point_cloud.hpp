#pragma once
#include <glm/glm.hpp>
#include <vector>

struct Point {
    glm::vec3 position;
    glm::vec3 color;
    float size;
};

class PointCloud {
public:
    void addPoint(const Point& point);
    const std::vector<Point>& getPoints() const;
    
private:
    std::vector<Point> m_points;
};