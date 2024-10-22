#pragma once
#include <glad/glad.h>
#include <string>
#include <glm/glm.hpp>

class Shader {
public:
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    void use();
    void setMat4(const std::string& name, const glm::mat4& mat);
    void setVec3(const std::string& name, const glm::vec3& value);
    void setFloat(const std::string& name, float value);

private:
    GLuint m_program;
    void checkCompileErrors(GLuint shader, const std::string& type);
};