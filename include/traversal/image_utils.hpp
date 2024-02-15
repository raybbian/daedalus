#ifndef IMAGE_UTILS_H
#define IMAGE_UTILS_H

#include <vector>
#include <optional>
#include <filesystem>

using pixel_t = std::tuple<uint8_t, uint8_t, uint8_t>;

enum Color {
    TAN,
    GRAY,
    YELLOW,
    RED,
    GREEN,
    BLUE,
    ORANGE,
    PURPLE,
    WHITE,
    BLACK,
};

std::vector<std::vector<pixel_t>> read_image_to_bytes(const std::filesystem::path& path);

std::vector<std::vector<Color>> convert_bytes_to_colors(std::vector<std::vector<pixel_t>> &bytes) noexcept(false);

#endif /* IMAGE_UTILS_H */
