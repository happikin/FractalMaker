#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_
#ifndef STDINT_H_
#define STDINT_H_
#include <stdint.h>
#endif

namespace happikin {
    struct  __attribute__((packed, aligned(2))) bitmapinfoheader {
        int32_t headerSize{40};
        int32_t width;
        int32_t height;
        int16_t planes;
        int16_t bitsPerPixel{24};
        int32_t compression{0};
        int32_t dataSize{0};
        int32_t horizontalResolution{2400};
        int32_t verticalResolution{2400};
        int32_t colors{0};
        int32_t importantColors{0};
    };
}

#endif