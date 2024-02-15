#include <iostream>
#include <optional>

#include "traversal/image_utils.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: no file provided" << std::endl;
        return 1;
    }
    std::string path = argv[1];
    std::cout << path << std::endl;
    auto img_pixels = read_image_to_bytes(path);
    std::vector<std::vector<Color>> img_colors;
    try {
        img_colors = convert_bytes_to_colors(img_pixels);
    } catch (std::exception &e) {
        std::cerr << "Error reading bytes to colors: " << e.what() << std::endl;
        return 1;
    }
    for (const auto &row: img_colors) {
        for (const auto color: row) {
            if (color == BLACK) std::cout << ". ";
            else std::cout << color << " ";
        }
        std::cout << std::endl;
    }
}
