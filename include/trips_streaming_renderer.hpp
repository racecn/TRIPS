#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "e57_loader.hpp"
#include <vector>
#include <queue>
#include <thread>
#include <mutex>

class TripsStreamingRenderer {
public:
    TripsStreamingRenderer(int width, int height, const std::string& e57File);
    ~TripsStreamingRenderer();
    
    void render();
    GLFWwindow* getWindow() const { return m_window; }

private:
    // Streaming buffer management
    static const size_t BATCH_SIZE = 1000000;  // 1M points per batch
    static const size_t MAX_LOADED_POINTS = 10000000;  // Keep 10M points in GPU memory
    
    struct PointBatch {
        std::vector<Point> points;
        glm::vec3 centerOfMass;
        float radius;
    };

    // Multi-threaded loading
    void loaderThread();
    void processNextBatch();
    
    // GPU resource management
    void uploadBatchToGPU(const PointBatch& batch);
    void removeDistantBatches();
    
    // TRIPS specific rendering
    void renderToPyramid();
    void upsampleAndMerge();
    
    // Member variables
    GLFWwindow* m_window;
    int m_width, m_height;
    
    // Streaming state
    std::unique_ptr<E57Loader::StreamingLoader> m_loader;
    std::thread m_loaderThread;
    std::mutex m_batchMutex;
    std::queue<PointBatch> m_pendingBatches;
    std::vector<PointBatch> m_loadedBatches;
    bool m_isLoading;
    
    // Camera and view state
    glm::mat4 m_view;
    glm::mat4 m_projection;
    glm::vec3 m_cameraPos;
    
    // OpenGL resources
    GLuint m_vao, m_vbo;
    std::unique_ptr<Shader> m_splatShader;
    std::vector<PyramidLevel> m_pyramid;
};