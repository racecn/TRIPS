cmake_minimum_required(VERSION 3.20)

# Specify vcpkg toolchain file if not defined
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
endif()

project(trips_renderer LANGUAGES C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable GLM experimental features
add_definitions(-DGLM_ENABLE_EXPERIMENTAL)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Set E57Format paths explicitly
set(E57Format_DIR "B:/trips/trips_renderer/external/e57install/lib/cmake/E57Format" 
    CACHE PATH "Path to E57Format cmake config")
set(E57Format_INCLUDE_DIR "B:/trips/trips_renderer/external/e57install/include"
    CACHE PATH "Path to E57Format include directory")

message(STATUS "Looking for E57Format in: ${E57Format_DIR}")
message(STATUS "E57Format include dir: ${E57Format_INCLUDE_DIR}")

# Find required packages
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(TinyXML2 CONFIG REQUIRED)
find_package(XercesC CONFIG REQUIRED)
find_package(E57Format REQUIRED)

# Add GLAD (OpenGL loading library)
add_library(glad STATIC
    external/glad/src/glad.c
)
target_include_directories(glad PUBLIC
    external/glad/include
)

# Collect source files for the project
file(GLOB_RECURSE PROJECT_SOURCES 
    "src/*.cpp"
)

file(GLOB_RECURSE PROJECT_HEADERS 
    "include/*.h"
    "include/*.hpp"
)

# Define the executable target
add_executable(trips_renderer
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS}
)

# Add include directories for the target
target_include_directories(trips_renderer
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${OPENGL_INCLUDE_DIR}
        ${E57Format_INCLUDE_DIR}
        ${XercesC_INCLUDE_DIRS}
        external/glad/include
)

# Link libraries for trips_renderer
target_link_libraries(trips_renderer
    PRIVATE
        OpenGL::GL
        glad
        glfw
        glm::glm
        tinyxml2::tinyxml2
        E57Format
        XercesC::XercesC
)


# Custom commands for copying DLLs to the output directory (Windows only)
if(WIN32)
    # Function to get DLL path from vcpkg and copy it to output directory
    function(copy_vcpkg_dll TARGET DLL_NAME)
        file(GLOB DLL_PATH "C:/vcpkg/installed/x64-windows/bin/${DLL_NAME}*.dll")
        if(DLL_PATH)
            add_custom_command(TARGET ${TARGET} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    ${DLL_PATH}
                    $<TARGET_FILE_DIR:${TARGET}>
            )
        endif()
    endfunction()

    # Copy necessary DLLs from vcpkg
    copy_vcpkg_dll(trips_renderer "xerces-c")
    copy_vcpkg_dll(trips_renderer "glfw3")
    copy_vcpkg_dll(trips_renderer "tinyxml2")

    # Copy E57Format DLLs if they exist
    file(GLOB E57_DLL_PATH 
        "B:/trips/trips_renderer/external/e57install/bin/*.dll"
        "B:/trips/trips_renderer/external/e57install/lib/*.dll"
    )
    if(E57_DLL_PATH)
        add_custom_command(TARGET trips_renderer POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${E57_DLL_PATH}
                $<TARGET_FILE_DIR:${TARGET}>
        )
    endif()
endif()

# Add shader directory to output (copy shaders after build)
add_custom_command(TARGET trips_renderer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/shaders
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/shaders
)

# Print configuration summary
message(STATUS "")
message(STATUS "TRIPS Renderer Configuration Summary")
message(STATUS "==================================")
message(STATUS "Build type:              ${CMAKE_BUILD_TYPE}")
message(STATUS "Install prefix:          ${CMAKE_INSTALL_PREFIX}")
message(STATUS "Binary output:           ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "Library output:          ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message(STATUS "E57Format_DIR:          ${E57Format_DIR}")
message(STATUS "E57Format_INCLUDE_DIRS: ${E57Format_INCLUDE_DIRS}")
message(STATUS "")
message(STATUS "Include paths:")

# Output the include directories for debugging
get_target_property(INCLUDES trips_renderer INCLUDE_DIRECTORIES)
if(INCLUDES)
    foreach(DIR ${INCLUDES})
        message(STATUS "  ${DIR}")
    endforeach()
endif()

message(STATUS "")

# Set working directory in Visual Studio for debugging
if(MSVC)
    set_property(TARGET trips_renderer 
        PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
    
    # Add compiler options for MSVC
    target_compile_options(trips_renderer PRIVATE
        /W4     # Warning level 4
        /MP     # Multi-processor compilation
        /EHsc   # Exception handling model
    )
endif()

# Add compilation definitions
target_compile_definitions(trips_renderer
    PRIVATE
        GLM_ENABLE_EXPERIMENTAL
        $<$<CONFIG:Debug>:_DEBUG>
        $<$<CONFIG:Release>:NDEBUG>
)

# Make sure the E57Format headers are found
if(NOT EXISTS "${E57Format_INCLUDE_DIR}/E57Format.h")
    message(FATAL_ERROR "E57Format.h not found in ${E57Format_INCLUDE_DIR}!")
endif()