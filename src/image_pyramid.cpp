#include "image_pyramid.hpp"

ImagePyramid::ImagePyramid(int baseWidth, int baseHeight, int levels)
    : m_baseWidth(baseWidth), m_baseHeight(baseHeight), m_levels(levels) {
    
    m_textures.resize(levels);
    glGenTextures(levels, m_textures.data());
    
    for (int i = 0; i < levels; ++i) {
        int width = baseWidth >> i;
        int height = baseHeight >> i;
        
        glBindTexture(GL_TEXTURE_2D, m_textures[i]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width, height, 0, GL_RGBA, 
                     GL_FLOAT, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
}

void ImagePyramid::clear() {
    for (GLuint tex : m_textures) {
        glBindTexture(GL_TEXTURE_2D, tex);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}