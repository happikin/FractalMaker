#ifndef BITMAP_H_
#define BITMAP_H_

#ifndef STRING_
#define STRING_
#include <string>
#endif

#include <memory>
namespace happikin {
    class bitmap {
        int _width{}, _height{};
        std::unique_ptr<uint8_t[]> _pixels{nullptr};
        public:
            bitmap(int width, int height);
            ~bitmap();
            bool write(std::string fileName);
            void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
    };
}

#endif