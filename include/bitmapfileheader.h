#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_
#ifndef STDINT_H_
#define STDINT_H_
#include <stdint.h>
#endif

namespace happikin {
    struct __attribute__((packed, aligned(2))) bitmapfileheader
    {
        char header[2]{'B','M'};    // 2 bytes
        int32_t file_size; // 4 bytes
        int32_t reserved{0};
        int32_t dataOffset;
    };
}

#endif