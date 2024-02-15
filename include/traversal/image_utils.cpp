#include <boost/gil.hpp>
#include <boost/gil/extension/io/png.hpp>
#include <boost/gil/extension/io/jpeg.hpp>
#include <optional>
#include <vector>
#include <filesystem>

#include "image_utils.hpp"

namespace bg = boost::gil;

std::vector<std::vector<pixel_t>> read_image_to_bytes(const std::filesystem::path &path) {
    bg::rgb8_image_t img;
    auto tag = bg::png_tag {};
    bg::read_and_convert_image(path, img, tag);

    std::vector<std::vector<pixel_t>> img_pixels(img.height(), std::vector<pixel_t>(img.width()));
    auto img_view = bg::view(img);
    for (int i = 0; i < img.height(); i++) {
        for (int j = 0; j < img.width(); j++) {
            auto pixel = img_view(j, i);
            unsigned char red = pixel[0];
            unsigned char green = pixel[1];
            unsigned char blue = pixel[2];
            img_pixels[i][j] = {red, green, blue};
        }
    }
    return img_pixels;
}

std::vector<std::vector<Color>> convert_bytes_to_colors(std::vector<std::vector<pixel_t>> &bytes) noexcept(false) {
    std::vector<std::vector<Color>> img_colors(bytes.size(), std::vector<Color>(bytes[0].size()));
    for (int i = 0; i < bytes.size(); i++) {
        for (int j = 0; j < bytes[i].size(); j++) {
            if      (bytes[i][j] == pixel_t{0xee, 0xc3, 0x9a}) img_colors[i][j] = Color::TAN;
            else if (bytes[i][j] == pixel_t{0x9b, 0xad, 0xb7}) img_colors[i][j] = Color::GRAY;
            else if (bytes[i][j] == pixel_t{0xfb, 0xf2, 0x36}) img_colors[i][j] = Color::YELLOW;
            else if (bytes[i][j] == pixel_t{0xac, 0x32, 0x32}) img_colors[i][j] = Color::RED;
            else if (bytes[i][j] == pixel_t{0x4b, 0x69, 0x2f}) img_colors[i][j] = Color::GREEN;
            else if (bytes[i][j] == pixel_t{0x63, 0x9b, 0xff}) img_colors[i][j] = Color::BLUE;
            else if (bytes[i][j] == pixel_t{0xdf, 0x71, 0x26}) img_colors[i][j] = Color::ORANGE;
            else if (bytes[i][j] == pixel_t{0xd7, 0x7b, 0xba}) img_colors[i][j] = Color::PURPLE;
            else if (bytes[i][j] == pixel_t{0xff, 0xff, 0xff}) img_colors[i][j] = Color::WHITE;
            else if (bytes[i][j] == pixel_t{0x00, 0x00, 0x00}) img_colors[i][j] = Color::BLACK;
            else {
                throw std::runtime_error("Invalid color found");
            }
        }
    }
    return img_colors;
}
