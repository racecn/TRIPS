#include "e57_loader.hpp"
#include <iostream>
#include <memory>

bool E57Loader::check_required_fields(const e57::StructureNode& prototype) {
    return prototype.isDefined("cartesianX") &&
           prototype.isDefined("cartesianY") &&
           prototype.isDefined("cartesianZ");
}

std::vector<Point> E57Loader::load_e57_file(const std::string& filename) {
    std::vector<Point> points;
    
    try {
        // Create ImageFile using the correct constructor
        e57::ImageFile imf(filename.c_str(), "r");  // Open in read mode
        
        // Get root and scan data
        e57::StructureNode root = static_cast<e57::StructureNode>(imf.root());
        e57::VectorNode data3D = static_cast<e57::VectorNode>(root.get("data3D"));
        
        if (data3D.childCount() == 0) {
            std::cerr << "No 3D data found in E57 file" << std::endl;
            return points;
        }

        // Get first scan
        e57::StructureNode scan = static_cast<e57::StructureNode>(data3D.get(0));
        e57::CompressedVectorNode points3D = static_cast<e57::CompressedVectorNode>(scan.get("points"));
        e57::StructureNode prototype = static_cast<e57::StructureNode>(points3D.prototype());

        // Verify required fields exist
        if (!check_required_fields(prototype)) {
            std::cerr << "Required fields missing in E57 file" << std::endl;
            return points;
        }

        // Set up read buffers
        size_t numPoints = points3D.childCount();
        std::vector<double> x_buffer(CHUNK_SIZE);
        std::vector<double> y_buffer(CHUNK_SIZE);
        std::vector<double> z_buffer(CHUNK_SIZE);
        
        // Optional buffers for color (initialized to white)
        std::vector<double> r_buffer(CHUNK_SIZE, 1.0);
        std::vector<double> g_buffer(CHUNK_SIZE, 1.0);
        std::vector<double> b_buffer(CHUNK_SIZE, 1.0);
        std::vector<double> size_buffer(CHUNK_SIZE, 1.0);  // Default size 1.0

        // Set up E57 buffers
        std::vector<e57::SourceDestBuffer> buffers;
        
        // Add position buffers
        buffers.push_back(e57::SourceDestBuffer(imf, "cartesianX", 
            x_buffer.data(), CHUNK_SIZE, true, true));
        buffers.push_back(e57::SourceDestBuffer(imf, "cartesianY", 
            y_buffer.data(), CHUNK_SIZE, true, true));
        buffers.push_back(e57::SourceDestBuffer(imf, "cartesianZ", 
            z_buffer.data(), CHUNK_SIZE, true, true));

        // Check and add color buffers if available
        bool hasColor = prototype.isDefined("colorRed") && 
                       prototype.isDefined("colorGreen") && 
                       prototype.isDefined("colorBlue");

        if (hasColor) {
            buffers.push_back(e57::SourceDestBuffer(imf, "colorRed", 
                r_buffer.data(), CHUNK_SIZE, true, true));
            buffers.push_back(e57::SourceDestBuffer(imf, "colorGreen", 
                g_buffer.data(), CHUNK_SIZE, true, true));
            buffers.push_back(e57::SourceDestBuffer(imf, "colorBlue", 
                b_buffer.data(), CHUNK_SIZE, true, true));
        }

        // Check and add size buffer if available
        bool hasSize = prototype.isDefined("size");
        if (hasSize) {
            buffers.push_back(e57::SourceDestBuffer(imf, "size", 
                size_buffer.data(), CHUNK_SIZE, true, true));
        }

        // Create reader
        e57::CompressedVectorReader reader = points3D.reader(buffers);

        // Reserve space for efficiency
        points.reserve(numPoints);

        // Read points in chunks
        unsigned gotCount;
        while ((gotCount = reader.read()) > 0) {
            for (unsigned i = 0; i < gotCount; i++) {
                points.emplace_back(
                    glm::vec3(static_cast<float>(x_buffer[i]), 
                             static_cast<float>(y_buffer[i]), 
                             static_cast<float>(z_buffer[i])),
                    glm::vec3(static_cast<float>(r_buffer[i]),
                             static_cast<float>(g_buffer[i]), 
                             static_cast<float>(b_buffer[i])),
                    size_buffer[i]
                );
            }
        }

        // Cleanup
        reader.close();
        imf.close();
        
        std::cout << "Successfully loaded " << points.size() << " points from E57 file" << std::endl;
    }
    catch (const e57::E57Exception& ex) {
        std::cerr << "E57 Error: " << ex.what() << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return points;
}