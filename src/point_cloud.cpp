#include "point_cloud.hpp"

void PointCloud::addPoint(const Point& point) {
    m_points.push_back(point);
}

const std::vector<Point>& PointCloud::getPoints() const {
    return m_points;
}