#include <iostream>
#include <E57Format.h>
#include "e57_loader.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <path to E57 file> [limit]\n";
        return -1;
    }

    // Get filename from command line
    std::string filename = argv[1];

    // Load points using our static loader method
    std::vector<Point> points = E57Loader::load_e57_file(filename);

    if (points.empty()) {
        std::cerr << "No points loaded from the file." << std::endl;
        return -1;
    }

    // Optional limit for printing points, default is all points
    size_t limit = points.size();
    if (argc >= 3) {
        limit = std::min(limit, static_cast<size_t>(std::stoul(argv[2])));
    }

    // Print information about the loaded points
    std::cout << "Loaded " << points.size() << " points from the file.\n";
    std::cout << "Displaying the first " << limit << " points:\n";

    // Iterate over the points and print each point's information
    for (size_t i = 0; i < limit; ++i) {
        const Point& point = points[i];
        std::cout << "Point " << i + 1 << " - Position: ("
                  << point.position.x << ", "  // x
                  << point.position.y << ", "  // y
                  << point.position.z << "), " // z
                  << "Color: ("
                  << point.color.r << ", "    // r
                  << point.color.g << ", "    // g
                  << point.color.b << "), "   // b
                  << "Size: " << point.size   // size instead of intensity
                  << std::endl;
    }

    return 0;
}