#include <iostream>

#include "traversal/image_utils.hpp"

int main() {
    auto img_pixels = read_image("img.png");
    for (const auto &row: img_pixels) {
        for (const auto &[red, green, blue]: row) {
            std::cout << "R: " << (int) red << " G: " << (int) green << " B: " << (int) blue << std::endl;
        }
    }
}
