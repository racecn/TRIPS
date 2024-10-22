#include "renderer.hpp"
#include <stdexcept>
#include <glm/gtc/matrix_transform.hpp>

Renderer::Renderer(int width, int height) 
    : m_width(width), m_height(height) {
    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW");
        
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    m_window = glfwCreateWindow(width, height, "TRIPS Renderer", nullptr, nullptr);
    if (!m_window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create window");
    }
    
    glfwMakeContextCurrent(m_window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw std::runtime_error("Failed to initialize GLAD");
        
    m_pyramid = std::make_unique<ImagePyramid>(width, height, 4);
    m_shader = std::make_unique<Shader>("shaders/splat.vert", "shaders/splat.frag");

    // Initialize camera matrices
    m_projection = glm::perspective(glm::radians(45.0f), float(width) / float(height), 0.1f, 100.0f);
    m_view = glm::lookAt(
        glm::vec3(0.0f, 0.0f, 5.0f),   // Camera position
        glm::vec3(0.0f, 0.0f, 0.0f),   // Look at point
        glm::vec3(0.0f, 1.0f, 0.0f)    // Up vector
    );

    setupPointRendering();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void Renderer::setupPointRendering() {
    glGenVertexArrays(1, &m_vao);
    glGenBuffers(1, &m_vbo);
    
    glBindVertexArray(m_vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    
    // Position attribute
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Point), (void*)offsetof(Point, position));
    
    // Color attribute
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Point), (void*)offsetof(Point, color));
    
    // Size attribute
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, sizeof(Point), (void*)offsetof(Point, size));
    
    glBindVertexArray(0);
}

Renderer::~Renderer() {
    glDeleteVertexArrays(1, &m_vao);
    glDeleteBuffers(1, &m_vbo);
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Renderer::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    if (!m_points.empty()) {
        m_shader->use();
        m_shader->setMat4("projection", m_projection);
        m_shader->setMat4("view", m_view);
        
        glBindVertexArray(m_vao);
        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
        glBufferData(GL_ARRAY_BUFFER, m_points.size() * sizeof(Point), m_points.data(), GL_DYNAMIC_DRAW);
        
        glDrawArrays(GL_POINTS, 0, m_points.size());
        glBindVertexArray(0);
    }
    
    m_pyramid->clear();
    glfwSwapBuffers(m_window);
}

void Renderer::addPoint(const Point& point) {
    m_points.push_back(point);
}

GLFWwindow* Renderer::getWindow() const {
    return m_window;
}