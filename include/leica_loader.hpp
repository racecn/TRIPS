#pragma once
#include "point_cloud.hpp"
#include <string>
#include <memory>

class LeicaLoader {
public:
    struct ScanInfo {
        size_t numPoints;
        glm::vec3 bounds_min;
        glm::vec3 bounds_max;
        float avgSpacing;
    };

    static PointCloud loadFromFile(const std::string& filename, bool normalize = true);
    static ScanInfo analyzeScan(const std::string& filename);
    
private:
    static void normalizePointCloud(std::vector<Point>& points);
    static float computeAverageSpacing(const std::vector<Point>& points, size_t sampleSize = 1000);
};