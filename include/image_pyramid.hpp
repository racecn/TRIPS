#pragma once
#include <glad/glad.h>
#include <vector>
#include <glm/glm.hpp>

class ImagePyramid {
public:
    ImagePyramid(int baseWidth, int baseHeight, int levels);
    void clear();
    GLuint getTextureID(int level) const { return m_textures[level]; }
    
private:
    std::vector<GLuint> m_textures;
    int m_levels;
    int m_baseWidth, m_baseHeight;
};