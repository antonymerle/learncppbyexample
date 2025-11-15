#include <cstddef>
#include <fstream>
#include <iostream>

void ppm()
{
    const char* path = "image.ppm";
    constexpr size_t w{16 * 60};
    constexpr size_t h{9 * 60};
    std::ofstream file(path, std::ios::binary);
    // << operator only writes text. The PPM header is text only
    file << "P6\n";
    file << w << " " << h << "\n";
    file << "255\n";

    // the body of the PPM is binary
    for (size_t y = 0; y < h; ++y) {
        for (size_t x = 0; x < w; ++x) {
            // divide x by 60 = column
            // divide y by 60 = row
            // add the two to get an index
            if ((x / 60 + y / 60) % 2) {
                // file.put(255) writes a single raw byte FF 00 00
                file.put(0xFF);
                file.put(0x00);
                file.put(0x00);
            } else {
                file.put(0x00);
                file.put(0xFF);
                file.put(0x00);
            }
        }
    }
    file.close();
    std::cout << "Generated " << path << "\n";
}
