#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>
#include <memory>
#include "point_cloud.hpp"
#include "image_pyramid.hpp"
#include "shader.hpp"

class Renderer {
public:
    Renderer(int width, int height);
    ~Renderer();
    
    void render();
    GLFWwindow* getWindow() const;
    void addPoint(const Point& point);
    
private:
    void setupPointRendering();

    std::unique_ptr<ImagePyramid> m_pyramid;
    std::unique_ptr<Shader> m_shader;
    GLFWwindow* m_window;
    int m_width, m_height;
    
    // OpenGL objects
    GLuint m_vao, m_vbo;
    std::vector<Point> m_points;
    
    // Camera
    glm::mat4 m_projection;
    glm::mat4 m_view;
};