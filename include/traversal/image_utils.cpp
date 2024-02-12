#include <boost/gil.hpp>
#include <boost/gil/extension/io/png.hpp>
#include <vector>
#include <filesystem>

#include "image_utils.hpp"

namespace bg = boost::gil;

std::vector<std::vector<pixel_t>> read_image(const std::filesystem::path &path) {
    bg::rgba8_image_t img;
    bg::read_image(path, img, bg::png_tag{});

    std::vector<std::vector<pixel_t>> img_pixels(img.height(), std::vector<pixel_t>(img.width()));
    auto img_view = bg::view(img);
    for (int i = 0; i < img.height(); i++) {
        for (int j = 0; j < img.height(); j++) {
            auto pixel = img_view(i, j);
            unsigned char red = pixel[0];
            unsigned char green = pixel[1];
            unsigned char blue = pixel[2];
            img_pixels[i][j] = {red, green, blue};
        }
    }

    return img_pixels;
}
