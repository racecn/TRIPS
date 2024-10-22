cmake_minimum_required(VERSION 3.20)

# Specify the vcpkg toolchain file
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
endif()

# Explicitly set the triplet for x64
set(VCPKG_TARGET_TRIPLET "x64-windows" CACHE STRING "Vcpkg target triplet")

project(trips_renderer LANGUAGES C CXX)  # Added C language support for GLAD

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add GLAD - specify C as the language
add_library(glad STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/external/glad/src/glad.c
)
set_target_properties(glad PROPERTIES
    C_STANDARD 11
    C_STANDARD_REQUIRED ON
)
target_include_directories(glad PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/external/glad/include
)

# Find required packages
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(OpenMP REQUIRED)

# Main executable
# Update the add_executable section to include shader.cpp
add_executable(trips_renderer
    src/main.cpp
    src/renderer.cpp
    src/point_cloud.cpp
    src/neural_network.cpp
    src/image_pyramid.cpp
    src/shader.cpp
)

# Include directories
target_include_directories(trips_renderer PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${OPENGL_INCLUDE_DIR}
)

# Link libraries
target_link_libraries(trips_renderer PRIVATE
    OpenGL::GL
    glad
    glfw
    glm::glm
    OpenMP::OpenMP_CXX
)

# Copy shaders to build directory
add_custom_command(TARGET trips_renderer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/shaders
    ${CMAKE_BINARY_DIR}/shaders
)