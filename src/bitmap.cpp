#include <iostream>
#include "../include/bitmap.h"
#include "../include/bitmapfileheader.h"
#include "../include/bitmapinfoheader.h"
#include <fstream>
using namespace happikin;
namespace happikin
{
    bitmap::bitmap(int width, int height) : _width(width), _height(height), _pixels(new uint8_t[width*height*3]{0}) {
        std::cout << "Constructor! \n";
    }
    bitmap::~bitmap() {}
    bool bitmap::write(std::string fileName) {
        std::cout << "WRITING TO BITMAP . . . \n";
        bitmapfileheader fileheader;
        bitmapinfoheader infoheader;
        fileheader.file_size = sizeof(bitmapfileheader)
                                + sizeof(bitmapinfoheader)
                                + _width*_height*3;
        fileheader.dataOffset = fileheader.file_size - _width*_height*3;
        // dataOffset indicates from which byte does actual data begin
        infoheader.width = _width;
        infoheader.height = _height;
        std::fstream outfile;
        outfile.open(fileName + ".bmp",std::ios::binary | std::ios::out);
        if(!outfile.is_open()) exit(1);

        outfile.write(reinterpret_cast<char *>(&fileheader),sizeof(fileheader));
        outfile.write(reinterpret_cast<char *>(&infoheader),sizeof(infoheader));
        outfile.write(reinterpret_cast<char *>(_pixels.get()),_width*_height*3);

        outfile.close();
        if(!outfile) return false;
        return true;
    }
    void bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
        //std::cout << "Setting RGB at pixel (" << x << "," << y << ")\n";
        uint8_t *pixelPtr  = _pixels.get();
        // we have a pointer to the first pixel over the image
        pixelPtr += (3*y) * _width + (3*x);
        // we have our pointer at the desired pixel over the image 
        // we multiply by 3 because we have RGB in every pixel
        pixelPtr[0] = blue;
        pixelPtr[1] = green;
        pixelPtr[2] = red;
        // we write in reverse oreder because bitmap is a little endian system

    }
} // namespace happikin
