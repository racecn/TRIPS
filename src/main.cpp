#include "renderer.hpp"
#include "leica_loader.hpp"
#include <iostream>
#include <chrono>

int main() {
    try {
        Renderer renderer(1920, 1080);
        
        // Analyze the scan first
        std::cout << "Analyzing Marble House scan..." << std::endl;
        auto info = LeicaLoader::analyzeScan("marblehouse.ply");
        std::cout << "Found " << info.numPoints << " points" << std::endl;
        
        // Load the point cloud
        std::cout << "Loading point cloud..." << std::endl;
        auto startTime = std::chrono::high_resolution_clock::now();
        
        PointCloud pointCloud = LeicaLoader::loadFromFile("marblehouse.ply", true);
        
        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
        
        std::cout << "Loading completed in " << duration.count() / 1000.0f << " seconds" << std::endl;
        
        // Add points to renderer
        const auto& points = pointCloud.getPoints();
        for (const auto& point : points) {
            renderer.addPoint(point);
        }
        
        // Main render loop
        while (!glfwWindowShouldClose(renderer.getWindow())) {
            renderer.render();
            glfwPollEvents();
            
            // Print FPS
            static int frameCount = 0;
            static auto lastTime = std::chrono::high_resolution_clock::now();
            frameCount++;
            
            auto currentTime = std::chrono::high_resolution_clock::now();
            if (std::chrono::duration_cast<std::chrono::seconds>(currentTime - lastTime).count() >= 1) {
                std::cout << "\rFPS: " << frameCount << std::flush;
                frameCount = 0;
                lastTime = currentTime;
            }
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }
    
    return 0;
}