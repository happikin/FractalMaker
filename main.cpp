#include <iostream>
//#include <stdint>
#include <math.h>
#include "../FractalMaker/include/bitmapfileheader.h"
#include "../FractalMaker/include/bitmapinfoheader.h"
#include "../FractalMaker/include/bitmap.h"
#include "../FractalMaker/include/mandelbrot.h"
using namespace happikin;
int main() {
    std::cout << sizeof(bitmapfileheader) << std::endl;
    std::cout << sizeof(bitmapinfoheader) << std::endl;
    mandelbrot f1;
    const int WIDTH{1920};
    const int HEIGHT{1080};
    const int w_offset = 0;
    const int h_offset = 0;
    bitmap img1{WIDTH,HEIGHT};
    double min = 99999;
    double max = -99999;
    int scaling_factor{0};
    if(WIDTH > HEIGHT) scaling_factor = HEIGHT;
    else scaling_factor = WIDTH;

    std::unique_ptr<int[]> colorHist(new int[mandelbrot::MAX_ITERATIONS]{0});
    std::unique_ptr<int[]> iterPerPixelList(new int[WIDTH*HEIGHT]{0});

    for(int j=h_offset ; j<HEIGHT-h_offset ; j++) {
        for(int i=w_offset ; i<WIDTH-w_offset ; i++) {
            double xFractal = ((i - w_offset) - (WIDTH - w_offset)/2 - 150)*(2.00/(scaling_factor-w_offset));
            double yFractal = ((j - h_offset) - (HEIGHT - h_offset)/2)*(2.00/(scaling_factor-h_offset));
            auto iterations = mandelbrot::getIterations(xFractal,yFractal);
            iterPerPixelList[j*WIDTH+i] = iterations;
            if(iterations != mandelbrot::MAX_ITERATIONS) colorHist[iterations]++;
            // img1.setPixel(j,i,255,0,0);
        }
    }

    // auto ptr = colorHist.get(); int i{0}; 
    // while(i < mandelbrot::MAX_ITERATIONS) { std::cout << *ptr << std::endl; i++; ptr++; }
    // std::cout << "Min: " << min << "Max: " << max << std::endl;
    // int sum{0};
    // for(int i=0 ; i<mandelbrot::MAX_ITERATIONS ; i++) {
    //     sum += colorHist[i];
    // }
    // std::cout << "Total pixels: " << sum << std::endl;
    // for(int i=300 ; i<500 ; i++) {
    //     for(int j=300 ; j<500 ; j++) {
    //         img1.setPixel(j,i,0,0,0);
    //     }
    // }
    
    int tot{0};
    for(int i=0 ; i<mandelbrot::MAX_ITERATIONS ; i++) tot+=colorHist[i];

    for(int j=h_offset ; j<HEIGHT-h_offset ; j++) {
        for(int i=w_offset ; i<WIDTH-w_offset ; i++) {
            uint8_t red{0},blue{0},green{0};
            auto iterations = iterPerPixelList[j*WIDTH+i];
            //uint8_t color = (uint8_t)(((double)iterations/mandelbrot::MAX_ITERATIONS) * 256);
            if(iterations != mandelbrot::MAX_ITERATIONS) {
                double hue{0.0};
                for(int i=0 ; i<=iterations ; i++) hue += double(colorHist[i])/tot;
                green = std::pow(255,hue);
            }
            // if(iterations == mandelbrot::MAX_ITERATIONS) {red = green = blue = 0;}
            // green = hue*255;
            img1.setPixel(i, j, red, green, blue);
            
            // if(color < min) min = color;
            // if(color > max) max = color;
        }
    }
    std::string file_name = "blackone";
    img1.write(file_name);
    return 0;
}