#ifndef IMAGE_UTILS_H
#define IMAGE_UTILS_H

#include <vector>
#include <filesystem>

using pixel_t = std::tuple<uint8_t, uint8_t, uint8_t>;

std::vector<std::vector<pixel_t>> read_image(const std::filesystem::path& path);

#endif