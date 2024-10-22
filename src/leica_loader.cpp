#include "leica_loader.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <random>
#include <glm/gtx/norm.hpp>

LeicaLoader::ScanInfo LeicaLoader::analyzeScan(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    ScanInfo info;
    info.bounds_min = glm::vec3(std::numeric_limits<float>::max());
    info.bounds_max = glm::vec3(-std::numeric_limits<float>::max());
    
    // Read header to get point count
    std::string line;
    while (std::getline(file, line)) {
        if (line.find("element vertex") != std::string::npos) {
            std::istringstream iss(line);
            std::string elem, vert;
            iss >> elem >> vert >> info.numPoints;
        }
        if (line == "end_header") break;
    }

    std::cout << "Analyzing scan with " << info.numPoints << " points..." << std::endl;
    return info;
}

PointCloud LeicaLoader::loadFromFile(const std::string& filename, bool normalize) {
    PointCloud pointCloud;
    std::ifstream file(filename, std::ios::binary);
    
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    // Skip header
    std::string line;
    size_t numPoints = 0;
    bool isIntensity = false;
    bool isColor = false;

    while (std::getline(file, line)) {
        if (line.find("element vertex") != std::string::npos) {
            std::istringstream iss(line);
            std::string elem, vert;
            iss >> elem >> vert >> numPoints;
        }
        else if (line.find("property float intensity") != std::string::npos) {
            isIntensity = true;
        }
        else if (line.find("property uchar red") != std::string::npos) {
            isColor = true;
        }
        if (line == "end_header") break;
    }

    // Progress tracking
    size_t progressStep = numPoints / 100;
    size_t nextProgress = progressStep;

    std::cout << "Loading " << numPoints << " points..." << std::endl;

    // Read points
    for (size_t i = 0; i < numPoints; ++i) {
        Point point;
        float x, y, z;
        file >> x >> y >> z;
        point.position = glm::vec3(x, y, z);

        if (isIntensity) {
            float intensity;
            file >> intensity;
            // Convert intensity to grayscale color
            point.color = glm::vec3(intensity);
        }
        else if (isColor) {
            unsigned int r, g, b;
            file >> r >> g >> b;
            point.color = glm::vec3(r / 255.0f, g / 255.0f, b / 255.0f);
        }
        else {
            // Default color based on height
            point.color = glm::vec3(0.7f); // Light gray
        }

        // Dynamic point size based on position (will be adjusted later)
        point.size = 0.005f;

        pointCloud.addPoint(point);

        // Progress indicator
        if (i >= nextProgress) {
            std::cout << "\rLoading progress: " << (i * 100 / numPoints) << "%" << std::flush;
            nextProgress += progressStep;
        }
    }

    std::cout << "\rLoading complete!                 " << std::endl;

    if (normalize) {
        normalizePointCloud(pointCloud.getPoints());
    }

    // Compute average spacing for point size adjustment
    float avgSpacing = computeAverageSpacing(pointCloud.getPoints());
    
    // Adjust point sizes based on average spacing
    for (auto& point : pointCloud.getPoints()) {
        point.size = avgSpacing * 2.0f; // Start with 2x average spacing
    }

    return pointCloud;
}

void LeicaLoader::normalizePointCloud(std::vector<Point>& points) {
    if (points.empty()) return;

    // Find bounds
    glm::vec3 min_bounds(std::numeric_limits<float>::max());
    glm::vec3 max_bounds(-std::numeric_limits<float>::max());

    for (const auto& point : points) {
        min_bounds = glm::min(min_bounds, point.position);
        max_bounds = glm::max(max_bounds, point.position);
    }

    // Calculate center and scale
    glm::vec3 center = (min_bounds + max_bounds) * 0.5f;
    float scale = 1.0f / glm::max(
        glm::max(max_bounds.x - min_bounds.x, max_bounds.y - min_bounds.y),
        max_bounds.z - min_bounds.z
    );

    // Normalize points
    for (auto& point : points) {
        point.position = (point.position - center) * scale;
    }
}

float LeicaLoader::computeAverageSpacing(const std::vector<Point>& points, size_t sampleSize) {
    if (points.size() < 2) return 0.0f;

    // Random sampling for efficiency
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, points.size() - 1);

    float totalSpacing = 0.0f;
    size_t samples = std::min(sampleSize, points.size());

    for (size_t i = 0; i < samples; ++i) {
        size_t idx = dis(gen);
        float minDist = std::numeric_limits<float>::max();
        
        // Find nearest neighbor
        for (size_t j = 0; j < points.size(); ++j) {
            if (j == idx) continue;
            float dist = glm::distance2(points[idx].position, points[j].position);
            minDist = std::min(minDist, dist);
        }
        
        totalSpacing += std::sqrt(minDist);
    }

    return totalSpacing / samples;
}